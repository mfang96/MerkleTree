import java.util.ArrayList;
import java.util.List;

public class main{
    public static void main(String[] args) {
        List<String> tempTxList = new ArrayList<String>();
        tempTxList.add("a1");
        tempTxList.add("a2");
        tempTxList.add("a3");
        tempTxList.add("a4");
        tempTxList.add("a5");

        MerkleTrees merkleTrees = new MerkleTrees(tempTxList);
        merkleTrees.merkle_tree();
        System.out.println("Merkle Root is: " + merkleTrees.getRoot());
    }
}

