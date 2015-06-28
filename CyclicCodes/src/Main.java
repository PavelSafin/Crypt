import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);

        new Interpreter().run(in);

    }

    static class Interpreter {
        public void run (InputReader in) throws IOException {
            Coder coder = new Coder(9, 5, 31);

            while (true) {
                System.out.print(">>> ");
                String command = in.next();
                int number = in.nextInt();

                if (command.equals("exit()"))
                    break;

                if (command.equals("encode")) {
                    System.out.println(coder.encode(number));
                    continue;
                }

                if (command.equals("decode")) {
                    System.out.println(coder.decode(number));
                    continue;
                }

                System.out.println("Unknown command");
            }
        }
    }
}
