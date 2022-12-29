#include <Windows.h>
#include <utility>
template<class T, class Closer, T invalid_value>class unique_handle
{
	T      handle;
	Closer closer;
public:
	unique_handle(T handle, Closer closer) noexcept
		: handle(handle)
		, closer(closer)
	{
	}
	~unique_handle()
	{
		if (handle != invalid_value)
			closer(handle);
	}
	unique_handle(unique_handle&& r) noexcept
		: handle(r.handle)
		, closer(r.closer)
	{
		r.handle = invalid_value;
	}
	unique_handle& operator=(unique_handle&& r) noexcept
	{
		std::swap(handle, r.handle);
		std::swap(closer, r.closer);
		return *this;
	}
	explicit operator bool() const noexcept
	{
		return handle != invalid_value;
	}
	T get() const noexcept
	{
		return handle;
	}
};
#ifdef 標準ライブラリを使用した場合
#include <fstream>
#include <sstream>
#endif
int main()
{
#ifdef 標準ライブラリを使用した場合
	OutputDebugStringA((std::ostringstream() << std::ifstream(__FILE__).rdbuf()).str().c_str());
#else
	if (const unique_handle<HANDLE, decltype(CloseHandle)*, INVALID_HANDLE_VALUE>
	hFile
	{ CreateFileA
		( /*_In_     LPCSTR                lpFileName           */__FILE__
		, /*_In_     DWORD                 dwDesiredAccess      */GENERIC_READ
		, /*_In_     DWORD                 dwShareMode          */FILE_SHARE_READ
		, /*_In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes */nullptr
		, /*_In_     DWORD                 dwCreationDisposition*/OPEN_EXISTING
		, /*_In_     DWORD                 dwFlagsAndAttributes */0
		, /*_In_opt_ HANDLE                hTemplateFile        */nullptr
		)
	, CloseHandle
	}) {
		//成功
		char buf[256];
		DWORD cbRead;
		if (ReadFile(hFile.get(), buf, sizeof buf - 1, &cbRead, nullptr)) {
			buf[cbRead] = '\0';
			OutputDebugStringA(buf);
			OutputDebugStringA("\n");
		}
	}
#endif
}
