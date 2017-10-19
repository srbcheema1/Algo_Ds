/*
* @author Nikunj Khokhar
*/
public class BinarySearchTree {


    class Node {
        int key;
        Node left, right;

        public Node(int item) {
            key = item;
            left = right = null;
        }
    }


    Node root;


    BinarySearchTree() {
        this.root = null;
    }


    void insert(int key) {
        root = insertRec(root, key);
    }


    Node insertRec(Node root, int key) {


        if (root == null) {
            root = new Node(key);
            return root;
        }


        if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);


        return root;
    }


    void inorder()  {
        inorderRec(root);
    }


    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.println(root.key);
            inorderRec(root.right);
        }
    }



    void preorder()  {
        preorderRec(root);
    }


    void preorderRec(Node root) {
        if (root != null) {
            System.out.println(root.key);
            preorderRec(root.left);
            preorderRec(root.right);
        }
    }



    void postorder()  {
        postorderRec(root);
    }


    void postorderRec(Node root) {
        if (root != null) {

            postorderRec(root.left);
            postorderRec(root.right);
            System.out.println(root.key);
        }
    }


}

public class Main {
    public static void main(String args[])
    {
        BinarySearchTree tree = new BinarySearchTree();
        tree.insert(50);
        tree.insert( 30);
        tree.insert( 20);
        tree.insert( 40);
        tree.insert( 70);
        tree.insert( 60);
        tree.insert(80);


        System.out.println("Inorder traversal of the given tree : ");
        tree.inorder();
        System.out.print("\n\n");


        System.out.println("Postorder traversal of the given tree : ");
        tree.postorder();
        System.out.print("\n\n");

        
        System.out.println("Preorder traversal of the given tree : ");
        tree.preorder();
    }
}
