package com.takayoshiotake.mylibrary;

import static java.lang.System.loadLibrary;

public class SampleClass {
    static {
        loadLibrary("mylibrary");
    }

    public SampleClass() { }

    public native String message();
}
