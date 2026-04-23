public class InheritanceDemo {

    static class Animal {
        String name = "Animal";

        void sound() {
            System.out.println("Animal makes a sound");
        }

        void breathe() {
            System.out.println("Animal breathes");
        }
    }

    static class Dog extends Animal {
        String name = "Dog";

        @Override
        void sound() {
            System.out.println("Dog barks");
        }

        void fetch() {
            System.out.println("Dog fetches the ball");
        }
    }

    public static void main(String[] args) {
        System.out.println("=== Base class reference → Derived class object (upcasting) ===");
        Animal a = new Dog();

        // Field access uses the reference type (Animal), NOT the actual object type
        System.out.println("a.name = " + a.name);        // "Animal" — field from Animal

        // Method calls use the actual object type (Dog) — runtime polymorphism
        a.sound();                                        // "Dog barks" — Dog's override
        a.breathe();                                      // "Animal breathes" — inherited

        // a.fetch();  // compile error — Animal ref doesn't know about fetch()

        System.out.println();
        System.out.println("=== Derived class reference → Derived class object ===");
        Dog d = new Dog();

        // Field access uses Dog's field
        System.out.println("d.name = " + d.name);        // "Dog" — field from Dog

        // Method calls still use Dog's override
        d.sound();                                        // "Dog barks"
        d.breathe();                                      // "Animal breathes" — inherited

        // Dog ref CAN access Dog-specific methods
        d.fetch();                                        // "Dog fetches the ball"

        System.out.println();
        System.out.println("=== Key differences ===");
        System.out.println("Fields   : resolved at compile time by reference type");
        System.out.println("Methods  : resolved at runtime by actual object type (polymorphism)");
        System.out.println("Access   : Animal ref cannot call Dog-specific methods (fetch)");

        System.out.println();
        System.out.println("=== Downcasting (Animal ref back to Dog) ===");
        Animal a2 = new Dog();
        if (a2 instanceof Dog dog) {
            dog.fetch();                                  // now accessible after downcast
        }
    }
}
