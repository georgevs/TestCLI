
In Visual Studio 2013 I have created a .NET 4.5 WPF C# application solution which also has a C++/CLI assembly and a native Win32 DLL. The app MainWindow XAML imports the namespace of the C++/CLI assembly and uses some classes defined in the assembly. Everything worked OK until I've added the a native Win32 DLL to which now the assembly depends. The solution still builds and runs properly provided that the WPF C# app .exe, the C++/CLI assembly .dll, and the Win32 .dll are in the same output folder. However the Visual Studio 2013 designer fails to load the app's MainWindow XAML page.

Apparently the designer makes its own private copy of the referenced C++/CLI assembly .dll when it loads the XAML. However since the native Win32 DLL is not on a well known path, the assembly fails to load.

I tried to modify the C++/CLI assembly reference Copy Local Build properties to True but it is reset to False immediately after I hit apply.

For the time being I am able to "resolve" the loading issue by adding my Release and Debug output directories to the system path, however this locks the native Win32 DLL file for writing once the designer opens the XAML once thus failing the building process.

Any hint or advice on how this can be properly solved is deeply appreciated.

Thanks, George