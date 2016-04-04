/*
    https://www.acmicpc.net/problem/9935
 */
import java.util.*;
class Pair {
    int first, second;
    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String expld = sc.nextLine();
        int inputLen = input.length();
        int expldLen = expld.length();
        boolean[] erased = new boolean[inputLen];
        if(expldLen == 1) {
            for(int i = 0; i < inputLen; i++) {
                if(input.charAt(i) == expld.charAt(0)) {
                    erased[i] = true;
                }
            }
        } else {
            Stack<Pair> stack = new Stack<>();
            for(int i = 0; i < inputLen; i++) {
                if(input.charAt(i) == expld.charAt(0)) {
                    stack.push(new Pair(i, 0));
                } else {
                    if(!stack.empty()) {
                        Pair pair = stack.peek();
                        if(input.charAt(i) == expld.charAt(pair.second + 1)) {
                            stack.push(new Pair(i, pair.second + 1));
                            if(pair.second + 1 == expldLen - 1) {
                                for(int k = 0; k < expldLen; k++) {
                                    Pair top = stack.pop();
                                    erased[top.first] = true;
                                }
                            }
                        } else {
                            while(!stack.empty()) {
                                stack.pop();
                            }
                        }
                    }
                }
            }
        }
        boolean printed = false;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < inputLen; i++) {
            if(!erased[i]) {
                sb.append(input.charAt(i));
                printed = true;
            }
        }
        if(printed) {
            System.out.println(sb);
        } else {
            System.out.println("FRULA");
        }
    }
}