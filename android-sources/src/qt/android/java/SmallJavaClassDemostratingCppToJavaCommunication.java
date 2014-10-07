package qt.android.java;

public class SmallJavaClassDemostratingCppToJavaCommunication {
    private static final String SOME_STRING = "Today is wednesday and your number is ";

    public static String getMeSomeStringWithMyNumber(int myNumber) {
        String str = SOME_STRING + String.valueOf(myNumber) + ".";
        return str;
    }
}
