// Win32Project1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Win32Project1.h"
#include <Windows.h>

using namespace Win32Project1;

class Model : public IModel {
public:
    Model() {
    }
    virtual ~Model() {
    }
    virtual void HelloWorld() override {
        ::MessageBox(NULL, TEXT("Hello World"), TEXT("Win32Project1"), 0);
    }
    virtual int state() override {
        return eStateOne;
    }
    virtual void setState(int value) override {
        // not implemented
    }
};

IModel* CreateModel() {
    return new Model();
}