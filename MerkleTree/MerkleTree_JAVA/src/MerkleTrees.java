import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

public class MerkleTrees {
	//transactiion list
	List<String> txList;
	//merkle root
	String root;
	
	/**
	 * constructor
	 * @param txList 交易list
	 */
	public MerkleTrees(List<String> txList){
		this.txList = txList;
		root = "";
	}
	
	/**
	 * execute merkle_tree and set root
	 */
	public void merkle_tree(){
		List<String> tempTxList = new ArrayList<String>();
		
		for(int i=0; i<this.txList.size(); i++){
			String shatx=jdksha256(this.txList.get(i));
			//计算叶子节点的hash值
//			System.out.println(shatx);
			tempTxList.add(shatx);
		}
//		System.out.println();

		List<String> newTxList = getNewTxList(tempTxList);
//		System.out.println();

		while (newTxList.size() != 1) {
			newTxList = getNewTxList(newTxList);
//			System.out.println();
		}
//		System.out.println();
		this.root = newTxList.get(0);
	}
	
	/**
	 * return node hash list
	 * @param tempLxList
	 * @return
	 */
	private List<String> getNewTxList(List<String> tempLxList){
		
		List<String> newTxList = new ArrayList<String>();
		int index = 0;
		
		while(index < tempLxList.size()){
			//left
			String left = tempLxList.get(index);
//			System.out.println(left);
			index++;

			//right
			String right = "";
			if(index != tempLxList.size()){
				right = tempLxList.get(index);
			}else{
				right=left;
			}
//			System.out.println(right);
			//sha2 hex value
			//String sha2HexValue = getSHA2HexValue(left + right);
			String sha2HexValue=left+right;
			String shatx=jdksha256(sha2HexValue);
			newTxList.add(shatx);
			index++;
		}
		
		return newTxList;		
	}
	
	
	/**
	 * Get Root
	 * @return
	 */
	public String getRoot(){
		return this.root;
	}

	/**
	 * 将byte数组转化为16进制输出
	 * @param bytes
	 * @return
	 */
	public static String convertByteToHexString(byte[] bytes){
		String result="";
		for(int i=0;i<bytes.length;i++){
			int temp=bytes[i] & 0xff;
			String tempHex=Integer.toHexString(temp);
			if(tempHex.length()<2){
				result+="0"+tempHex;
			}else{
				result+=tempHex;
			}
		}
		return result;
	}

	/**
	 * jdk实现sha256加密算法
	 */
	public static String jdksha256(String message){
		String shatx="";
		try{
			MessageDigest sha256Digest=MessageDigest.getInstance("SHA-256");
			byte[] sha256Encode=sha256Digest.digest(message.getBytes());
			shatx=convertByteToHexString((sha256Encode));
//			System.out.println("jdk sha256加密后为： "+convertByteToHexString((sha256Encode)));
		}catch(NoSuchAlgorithmException e){
			e.printStackTrace();
		}
		return shatx;
	}
}
