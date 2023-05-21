public class Main {
    public static void main(String[] args){
        Window win1 = new Window(1);
        Window win2 = new Window(2);
        Window win3 = new Window(3);
        System.out.println("Start sell tickets...");
        win1.start();
        win2.start();
        win3.start();
        System.out.println("Sell tickets finished...");
    }
}



class Window extends Thread {

    static int total=15; // Total 100 tickets
    static Integer now=1; // Number of ticket on sale
    final int ID;

    public Window(int id){ this.ID = id; }

    @Override
    public void run() {
        while(true){
            synchronized (Window.class) {
                if (now <= total)
                    System.out.println("Sell ticket number "+now+" in window "+this.ID);
                else break;
                now++;
            }
            try { Thread.sleep((int)(Math.random()*100)); }
            catch (InterruptedException e) { throw new RuntimeException(e); }
        }
    }
}

