/NIMA FATHIMA - 46
public class Demo {
    static class Object {
        public Object() {
            System.out.println("Object created");
        }
        protected void finalize() throws Throwable {
            System.out.println("Object is being garbage collected");
            super.finalize();
        }
    }

    public static void main(String[] args) {
        Object obj = new Object();
        obj = null;
        System.out.println("Requesting garbage collection");
        System.gc();
    }
}
