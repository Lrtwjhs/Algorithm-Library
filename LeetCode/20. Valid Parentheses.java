
/**
 * Created by lrtwjhs on 2018/6/24.
 */

class Solution {
    public boolean isValid(String s) {
        char[] stack = new char[s.length()];
        int top = -1;

        for (char c : s.toCharArray()) {
            switch (c) {
                case ')':
                    if (top >= 0 && stack[top] == '(') {
                        top--;
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (top >= 0 && stack[top] == '{') {
                        top--;
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (top >= 0 && stack[top] == '[') {
                        top--;
                    } else {
                        return false;
                    }
                    break;
                default:
                    stack[++top] = c;
                    break;
            }
        }
        return top < 0;
    }
}