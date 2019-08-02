package com.ming.utils;

public class OpenCVUtils {

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public static native String test();

    public static native void convertBytesToRGB(byte mode, byte rotate, byte mirror, int width, int height, byte[] dataIn, byte[] dataOut);
}
