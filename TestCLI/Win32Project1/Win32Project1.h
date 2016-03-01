// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the WIN32PROJECT1_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// WIN32PROJECT1_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef WIN32PROJECT1_EXPORTS
#define WIN32PROJECT1_API __declspec(dllexport)
#else
#define WIN32PROJECT1_API __declspec(dllimport)
#endif

namespace Win32Project1 {

enum EState {
    eStateOne,
    eStateTwo, 
    eStateThree
};

class IModel {
public:
    virtual ~IModel() {}
    virtual void HelloWorld() = 0;
    virtual int state() = 0;
    virtual void setState(int value) = 0;
};

} // namespace Win32Project1

WIN32PROJECT1_API Win32Project1::IModel* CreateModel();