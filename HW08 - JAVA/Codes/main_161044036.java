/**
 * @author Furkan Ozev
 * @since 17-01-2019
 */
public class main_161044036 {

	/**
	 * Test All functions and codes. Approximately 96% of the code successfully tested.
	 * @param args String
	 */
	public static void main(String args[])
	{
		System.out.print("---------------------- TEST ----------------------");
			
		{
			System.out.println("\n\n-------------Integer HashSet Test-------------\n");
			Integer[] arr1 = {3,7,4,9,2};
			Integer[] arr2 = {7,1,4,6,3};
			Integer[] arr3 = {2,7,11,8,3};
			HashSet<Integer> hset1 = new HashSet<Integer>(arr1);
			HashSet<Integer> hset2 = new HashSet<Integer>(arr2);
			HashSet<Integer> hset3 = new HashSet<Integer>(arr3);
			
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			System.out.format("HashSet 3 : %s \n",hset3);
			
			System.out.print("\n\na) add function: add 12 to HashSet1 and add 12 to HashSet2: \n");
			hset1.add(12);
			hset2.add(12);
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			
			System.out.print("\n\nb) addAll function: Add HashSet2 to HashSet1: \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			hset1.addAll(hset2);
			System.out.println("\tAfter HashSet1.addAll(HashSet2)");
			System.out.format("HashSet 1 : %s \n",hset1);
			
			System.out.print("\n\nc) contains function: HashSet1 contains 9 and HashSet2 contains 9: \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			if(hset1.contains(9)) System.out.print("\nFor HashSet1 true");
			else System.out.print("\nFor HashSet1 false");
			if(hset2.contains(9)) System.out.print("\tFor HashSet2 true");
			else System.out.print("\tFor HashSet2 false");
			
			System.out.print("\n\nd) containsAll function: HashSet1 contains HashSet2 and HashSet1 contains HashSet3: \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			System.out.format("HashSet 3 : %s \n",hset3);
			if(hset1.containsAll(hset2)) System.out.print("\nHashSet1 containsAll HashSet2 true");
			else System.out.print("\nHashSet1 containsAll HashSet2 false");
			if(hset1.containsAll(hset3)) System.out.print("\tHashSet1 containsAll HashSet3 true");
			else System.out.print("\tHashSet1 containsAll HashSet3 false");
			
			System.out.print("\n\ne) size function: For HashSet1 , HashSet2 , HashSet3: \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			System.out.format("HashSet 3 : %s \n",hset3);
			System.out.format("\nHashSet 1 size = %d , HashSet 2 size = %d , HashSet 3 size = %d", hset1.size(),hset2.size(),hset3.size());
		
			System.out.print("\n\nf) remove function: remove 1 to HashSet1, HashSet2 and HashSet3: \n");
			hset1.remove(1);
			hset2.remove(1);
			hset3.remove(1);
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			System.out.format("HashSet 3 : %s \n",hset3);
			System.out.format("\nHashSet 1 size = %d , HashSet 2 size = %d , HashSet 3 size = %d", hset1.size(),hset2.size(),hset3.size());
			
			System.out.print("\n\ng) retainAll function: Base HashSet1 Parameter HashSet3: \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 3 : %s \n",hset3);
			hset1.retainAll(hset3);
			System.out.println("\tAfter HashSet1.retainAll(HashSet3)");
			System.out.format("HashSet 1 : %s \n",hset1);
			
			System.out.print("\n\nh) removeAll function: Base HashSet2 Parameter HashSet3: \n");
			System.out.format("HashSet 2 : %s \n",hset2);
			System.out.format("HashSet 3 : %s \n",hset3);
			hset2.removeAll(hset3);
			System.out.println("\tAfter HashSet2.removeAll(HashSet3)");
			System.out.format("HashSet 2 : %s \n",hset2);
			
			System.out.print("\n\ni) clear function: HashSet1 : \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			hset1.clear();
			System.out.println("\tAfter HashSet1.clear()");
			System.out.format("HashSet 1 : %s \n",hset1);
			
			System.out.print("\n\nj) isEmpty function: HashSet1, HashSet2 : \n");
			System.out.format("HashSet 1 : %s    HashSet 2 : %s ",hset1,hset2);
			if(hset1.isEmpty()) System.out.print("\nHashSet1 is empty");
			else System.out.print("\nHashSet1 is not empty");
			if(hset2.isEmpty()) System.out.print("\tHashSet2 is empty");
			else System.out.print("\tHashSet2 is not empty");
			
			System.out.println("\n\n HashSet Integer test successfully completed. \n");
		}
		
		{
			System.out.println("\n\n-------------String HashSet Test-------------\n");
			String[] arr1 = {"Mango","Orange","Pear","Cherries","Banana"};
			String[] arr2 = {"Orange","Apple","Pear","Grapes","Mango"};
			String[] arr3 = {"Banana","Orange","Mandarin","Pineapple","Mango"};
			HashSet<String> hset1 = new HashSet<String>(arr1);
			HashSet<String> hset2 = new HashSet<String>(arr2);
			HashSet<String> hset3 = new HashSet<String>(arr3);
			
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			System.out.format("HashSet 3 : %s \n",hset3);
			
			System.out.print("\n\na) add function: add \"Strawberries\" to HashSet1 and add \"Strawberries\" to HashSet2: \n");
			hset1.add("Strawberries");
			hset2.add("Strawberries");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			
			System.out.print("\n\nb) addAll function: Add HashSet2 to HashSet1: \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			hset1.addAll(hset2);
			System.out.println("\tAfter HashSet1.addAll(HashSet2)");
			System.out.format("HashSet 1 : %s \n",hset1);
			
			System.out.print("\n\nc) contains function: HashSet1 contains \"Cherries\" and HashSet2 contains \"Cherries\": \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			if(hset1.contains("Cherries")) System.out.print("\nFor HashSet1 true");
			else System.out.print("\nFor HashSet1 false");
			if(hset2.contains("Cherries")) System.out.print("\tFor HashSet2 true");
			else System.out.print("\tFor HashSet2 false");
			
			System.out.print("\n\nd) containsAll function: HashSet1 contains HashSet2 and HashSet1 contains HashSet3: \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			System.out.format("HashSet 3 : %s \n",hset3);
			if(hset1.containsAll(hset2)) System.out.print("\nHashSet1 containsAll HashSet2 true");
			else System.out.print("\nHashSet1 containsAll HashSet2 false");
			if(hset1.containsAll(hset3)) System.out.print("\tHashSet1 containsAll HashSet3 true");
			else System.out.print("\tHashSet1 containsAll HashSet3 false");
			
			System.out.print("\n\ne) size function: For HashSet1 , HashSet2 , HashSet3: \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			System.out.format("HashSet 3 : %s \n",hset3);
			System.out.format("\nHashSet 1 size = %d , HashSet 2 size = %d , HashSet 3 size = %d", hset1.size(),hset2.size(),hset3.size());
		
			System.out.print("\n\nf) remove function: remove \"Apple\" to HashSet1, HashSet2 and HashSet3: \n");
			hset1.remove("Apple");
			hset2.remove("Apple");
			hset3.remove("Apple");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 2 : %s \n",hset2);
			System.out.format("HashSet 3 : %s \n",hset3);
			System.out.format("\nHashSet 1 size = %d , HashSet 2 size = %d , HashSet 3 size = %d", hset1.size(),hset2.size(),hset3.size());
			
			System.out.print("\n\ng) retainAll function: Base HashSet1 Parameter HashSet3: \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			System.out.format("HashSet 3 : %s \n",hset3);
			hset1.retainAll(hset3);
			System.out.println("\tAfter HashSet1.retainAll(HashSet3)");
			System.out.format("HashSet 1 : %s \n",hset1);
			
			System.out.print("\n\nh) removeAll function: Base HashSet2 Parameter HashSet3: \n");
			System.out.format("HashSet 2 : %s \n",hset2);
			System.out.format("HashSet 3 : %s \n",hset3);
			hset2.removeAll(hset3);
			System.out.println("\tAfter HashSet2.removeAll(HashSet3)");
			System.out.format("HashSet 2 : %s \n",hset2);
			
			System.out.print("\n\ni) clear function: HashSet1 : \n");
			System.out.format("HashSet 1 : %s \n",hset1);
			hset1.clear();
			System.out.println("\tAfter HashSet1.clear()");
			System.out.format("HashSet 1 : %s \n",hset1);
			
			System.out.print("\n\nj) isEmpty function: HashSet1, HashSet2 : \n");
			System.out.format("HashSet 1 : %s    HashSet 2 : %s ",hset1,hset2);
			if(hset1.isEmpty()) System.out.print("\nHashSet1 is empty");
			else System.out.print("\nHashSet1 is not empty");
			if(hset2.isEmpty()) System.out.print("\tHashSet2 is empty");
			else System.out.print("\tHashSet2 is not empty");
			
			System.out.println("\n\n HashSet String test successfully completed. \n");
		}
		
		{
			System.out.println("\n\n-------------Integer ArrayList Test-------------\n");
			Integer[] arr1 = {3,7,4,9,2};
			Integer[] arr2 = {7,1,4,6,3};
			Integer[] arr3 = {2,7,11,8,3};
			ArrayList<Integer> alist1 = new ArrayList<Integer>(arr1);
			ArrayList<Integer> alist2 = new ArrayList<Integer>(arr2);
			ArrayList<Integer> alist3 = new ArrayList<Integer>(arr3);
			
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			System.out.format("ArrayList 3 : %s \n",alist3);
			
			System.out.print("\n\na) add function: add 12 to ArrayList1 and add 12 to ArrayList2: \n");
			alist1.add(12);
			alist2.add(12);
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			
			System.out.print("\n\nb) addAll function: Add ArrayList2 to ArrayList1: \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			alist1.addAll(alist2);
			System.out.println("\tAfter ArrayList1.addAll(ArrayList2)");
			System.out.format("ArrayList 1 : %s \n",alist1);
			
			System.out.print("\n\nc) contains function: ArrayList1 contains 9 and ArrayList2 contains 9: \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			if(alist1.contains(9)) System.out.print("\nFor ArrayList1 true");
			else System.out.print("\nFor ArrayList1 false");
			if(alist2.contains(9)) System.out.print("\tFor ArrayList2 true");
			else System.out.print("\tFor ArrayList2 false");
			
			System.out.print("\n\nd) containsAll function: ArrayList1 contains ArrayList2 and ArrayList1 contains ArrayList3: \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			System.out.format("ArrayList 3 : %s \n",alist3);
			if(alist1.containsAll(alist2)) System.out.print("\nArrayList1 containsAll ArrayList2 true");
			else System.out.print("\nArrayList1 containsAll ArrayList2 false");
			if(alist1.containsAll(alist3)) System.out.print("\tArrayList1 containsAll ArrayList3 true");
			else System.out.print("\tArrayList1 containsAll ArrayList3 false");
			
			System.out.print("\n\ne) size function: For ArrayList1 , ArrayList2 , ArrayList3: \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			System.out.format("ArrayList 3 : %s \n",alist3);
			System.out.format("\nArrayList 1 size = %d , ArrayList 2 size = %d , ArrayList 3 size = %d", alist1.size(),alist2.size(),alist3.size());
		
			System.out.print("\n\nf) remove function: remove 1 to ArrayList1, ArrayList2 and ArrayList3: \n");
			alist1.remove(1);
			alist2.remove(1);
			alist3.remove(1);
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			System.out.format("ArrayList 3 : %s \n",alist3);
			System.out.format("\nArrayList 1 size = %d , ArrayList 2 size = %d , ArrayList 3 size = %d", alist1.size(),alist2.size(),alist3.size());
			
			System.out.print("\n\ng) retainAll function: Base ArrayList1 Parameter ArrayList3: \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 3 : %s \n",alist3);
			alist1.retainAll(alist3);
			System.out.println("\tAfter ArrayList1.retainAll(ArrayList3)");
			System.out.format("ArrayList 1 : %s \n",alist1);
			
			System.out.print("\n\nh) removeAll function: Base ArrayList2 Parameter ArrayList3: \n");
			System.out.format("ArrayList 2 : %s \n",alist2);
			System.out.format("ArrayList 3 : %s \n",alist3);
			alist2.removeAll(alist3);
			System.out.println("\tAfter ArrayList2.removeAll(ArrayList3)");
			System.out.format("ArrayList 2 : %s \n",alist2);
			
			System.out.print("\n\ni) clear function: ArrayList1 : \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			alist1.clear();
			System.out.println("\tAfter ArrayList1.clear()");
			System.out.format("ArrayList 1 : %s \n",alist1);
			
			System.out.print("\n\nj) isEmpty function: ArrayList1, ArrayList2 : \n");
			System.out.format("ArrayList 1 : %s    ArrayList 2 : %s ",alist1,alist2);
			if(alist1.isEmpty()) System.out.print("\nArrayList1 is empty");
			else System.out.print("\nArrayList1 is not empty");
			if(alist2.isEmpty()) System.out.print("\tArrayList2 is empty");
			else System.out.print("\tArrayList2 is not empty");
			
			System.out.println("\n\n ArrayList Integer test successfully completed. \n");
		}

	
		{
			System.out.println("\n\n-------------String ArrayList Test-------------\n");
			String[] arr1 = {"Mango","Orange","Pear","Cherries","Banana"};
			String[] arr2 = {"Orange","Apple","Pear","Grapes","Mango"};
			String[] arr3 = {"Banana","Orange","Mandarin","Pineapple","Mango"};
			ArrayList<String> alist1 = new ArrayList<String>(arr1);
			ArrayList<String> alist2 = new ArrayList<String>(arr2);
			ArrayList<String> alist3 = new ArrayList<String>(arr3);
			
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			System.out.format("ArrayList 3 : %s \n",alist3);
			
			System.out.print("\n\na) add function: add \"Strawberries\" to ArrayList1 and add \"Strawberries\" to ArrayList2: \n");
			alist1.add("Strawberries");
			alist2.add("Strawberries");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			
			System.out.print("\n\nb) addAll function: Add ArrayList2 to ArrayList1: \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			alist1.addAll(alist2);
			System.out.println("\tAfter ArrayList1.addAll(ArrayList2)");
			System.out.format("ArrayList 1 : %s \n",alist1);
			
			System.out.print("\n\nc) contains function: ArrayList1 contains \"Cherries\" and ArrayList2 contains \"Cherries\": \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			if(alist1.contains("Cherries")) System.out.print("\nFor ArrayList1 true");
			else System.out.print("\nFor ArrayList1 false");
			if(alist2.contains("Cherries")) System.out.print("\tFor ArrayList2 true");
			else System.out.print("\tFor ArrayList2 false");
			
			System.out.print("\n\nd) containsAll function: ArrayList1 contains ArrayList2 and ArrayList1 contains ArrayList3: \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			System.out.format("ArrayList 3 : %s \n",alist3);
			if(alist1.containsAll(alist2)) System.out.print("\nArrayList1 containsAll ArrayList2 true");
			else System.out.print("\nArrayList1 containsAll ArrayList2 false");
			if(alist1.containsAll(alist3)) System.out.print("\tArrayList1 containsAll ArrayList3 true");
			else System.out.print("\tArrayList1 containsAll ArrayList3 false");
			
			System.out.print("\n\ne) size function: For ArrayList1 , ArrayList2 , ArrayList3: \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			System.out.format("ArrayList 3 : %s \n",alist3);
			System.out.format("\nArrayList 1 size = %d , ArrayList 2 size = %d , ArrayList 3 size = %d", alist1.size(),alist2.size(),alist3.size());
		
			System.out.print("\n\nf) remove function: remove \"Apple\" to ArrayList1, ArrayList2 and ArrayList3: \n");
			alist1.remove("Apple");
			alist2.remove("Apple");
			alist3.remove("Apple");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 2 : %s \n",alist2);
			System.out.format("ArrayList 3 : %s \n",alist3);
			System.out.format("\nArrayList 1 size = %d , ArrayList 2 size = %d , ArrayList 3 size = %d", alist1.size(),alist2.size(),alist3.size());
			
			System.out.print("\n\ng) retainAll function: Base ArrayList1 Parameter ArrayList3: \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			System.out.format("ArrayList 3 : %s \n",alist3);
			alist1.retainAll(alist3);
			System.out.println("\tAfter ArrayList1.retainAll(ArrayList3)");
			System.out.format("ArrayList 1 : %s \n",alist1);
			
			System.out.print("\n\nh) removeAll function: Base ArrayList2 Parameter ArrayList3: \n");
			System.out.format("ArrayList 2 : %s \n",alist2);
			System.out.format("ArrayList 3 : %s \n",alist3);
			alist2.removeAll(alist3);
			System.out.println("\tAfter ArrayList2.removeAll(ArrayList3)");
			System.out.format("ArrayList 2 : %s \n",alist2);
			
			System.out.print("\n\ni) clear function: ArrayList1 : \n");
			System.out.format("ArrayList 1 : %s \n",alist1);
			alist1.clear();
			System.out.println("\tAfter ArrayList1.clear()");
			System.out.format("ArrayList 1 : %s \n",alist1);
			
			System.out.print("\n\nj) isEmpty function: ArrayList1, ArrayList2 : \n");
			System.out.format("ArrayList 1 : %s    ArrayList 2 : %s ",alist1,alist2);
			if(alist1.isEmpty()) System.out.print("\nArrayList1 is empty");
			else System.out.print("\nArrayList1 is not empty");
			if(alist2.isEmpty()) System.out.print("\tArrayList2 is empty");
			else System.out.print("\tArrayList2 is not empty");
			
			System.out.println("\n\n ArrayList String test successfully completed. \n");
		}
		
		{
			System.out.println("\n\n-------------Integer LinkedList Test-------------\n");
			Integer[] arr1 = {3,7,4,9,2};
			Integer[] arr2 = {7,1,4,6,3};
			Integer[] arr3 = {2,7,11,8,3};
			LinkedList<Integer> llist1 = new LinkedList<Integer>(arr1);
			LinkedList<Integer> llist2 = new LinkedList<Integer>(arr2);
			LinkedList<Integer> llist3 = new LinkedList<Integer>(arr3);
			
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			
			System.out.print("\n\na) add function: add 12 to LinkedList1 and add 12 to LinkedList2: \n");
			llist1.add(12);
			llist2.add(12);
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			
			System.out.print("\n\nb) addAll function: Add LinkedList2 to LinkedList1: \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			llist1.addAll(llist2);
			System.out.println("\tAfter LinkedList1.addAll(LinkedList2)");
			System.out.format("LinkedList 1 : %s \n",llist1);
			
			System.out.print("\n\nc) contains function: LinkedList1 contains 9 and LinkedList2 contains 9: \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			if(llist1.contains(9)) System.out.print("\nFor LinkedList1 true");
			else System.out.print("\nFor LinkedList1 false");
			if(llist2.contains(9)) System.out.print("\tFor LinkedList2 true");
			else System.out.print("\tFor LinkedList2 false");
			
			System.out.print("\n\nd) containsAll function: LinkedList1 contains LinkedList2 and LinkedList1 contains LinkedList3: \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			if(llist1.containsAll(llist2)) System.out.print("\nLinkedList1 containsAll LinkedList2 true");
			else System.out.print("\nLinkedList1 containsAll LinkedList2 false");
			if(llist1.containsAll(llist3)) System.out.print("\tLinkedList1 containsAll LinkedList3 true");
			else System.out.print("\tLinkedList1 containsAll LinkedList3 false");
			
			System.out.print("\n\ne) size function: For LinkedList1 , LinkedList2 , LinkedList3: \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			System.out.format("\nLinkedList 1 size = %d , LinkedList 2 size = %d , LinkedList 3 size = %d", llist1.size(),llist2.size(),llist3.size());

			System.out.print("\n\nf) remove function: remove 1 to LinkedList1, LinkedList2 and LinkedList3: \n");
			llist1.remove(1);
			llist2.remove(1);
			llist3.remove(1);
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			System.out.format("\nLinkedList 1 size = %d , LinkedList 2 size = %d , LinkedList 3 size = %d", llist1.size(),llist2.size(),llist3.size());
			
			System.out.print("\n\ng) retainAll function: Base LinkedList1 Parameter LinkedList3: \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 3 : %s \n",llist3);
			llist1.retainAll(llist3);
			System.out.println("\tAfter LinkedList1.retainAll(LinkedList3)");
			System.out.format("LinkedList 1 : %s \n",llist1);
			
			System.out.print("\n\nh) removeAll function: Base LinkedList2 Parameter LinkedList3: \n");
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			llist2.removeAll(llist3);
			System.out.println("\tAfter LinkedList2.removeAll(LinkedList3)");
			System.out.format("LinkedList 2 : %s \n",llist2);
			
			System.out.print("\n\ni) clear function: LinkedList1 : \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			llist1.clear();
			System.out.println("\tAfter LinkedList1.clear()");
			System.out.format("LinkedList 1 : %s \n",llist1);
			
			System.out.print("\n\nj) isEmpty function: LinkedList1, LinkedList2 : \n");
			System.out.format("LinkedList 1 : %s    LinkedList 2 : %s ",llist1,llist2);
			if(llist1.isEmpty()) System.out.print("\nLinkedList1 is empty");
			else System.out.print("\nLinkedList1 is not empty");
			if(llist2.isEmpty()) System.out.print("\tLinkedList2 is empty");
			else System.out.print("\tLinkedList2 is not empty");
			
			System.out.print("\n\nk) element function: LinkedList2, LinkedList3 : \n");
			System.out.format("LinkedList 2 : %s  \nhead value = %d  \nLinkedList 3 : %s \nhead value = %d",llist2,llist2.element(),llist3,llist3.element());
			
			System.out.print("\n\nl) offer function: insert 19 into LinkedList2, LinkedList3 : \n");
			llist2.offer(19);
			llist3.offer(19);
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			
			System.out.print("\n\nk) pool function: LinkedList2, LinkedList3 : \n");
			int temp1;
			int temp2;
			try {
				temp1 = llist2.poll();
				temp2 = llist3.poll();
				System.out.format("LinkedList 2 : %s  \nold head value = %d \nnew head value = %d  \n\nLinkedList 3 : %s  \nold head value = %d \nnew head value = %d",llist2,temp1,llist2.element(),llist3,temp2,llist3.element());
			} catch (MyException err) {
				System.out.println(err.getMessage());
			}
			
			System.out.println("\n\n LinkedList Integer test successfully completed. \n");
		}
		
		{
			System.out.println("\n\n-------------String LinkedList Test-------------\n");
			String[] arr1 = {"Mango","Orange","Pear","Cherries","Banana"};
			String[] arr2 = {"Orange","Apple","Pear","Grapes","Mango"};
			String[] arr3 = {"Banana","Orange","Mandarin","Pineapple","Mango"};
			LinkedList<String> llist1 = new LinkedList<String>(arr1);
			LinkedList<String> llist2 = new LinkedList<String>(arr2);
			LinkedList<String> llist3 = new LinkedList<String>(arr3);
			
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			
			System.out.print("\n\na) add function: add \"Strawberries\" to LinkedList1 and add \"Strawberries\" to LinkedList2: \n");
			llist1.add("Strawberries");
			llist2.add("Strawberries");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			
			System.out.print("\n\nb) addAll function: Add LinkedList2 to LinkedList1: \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			llist1.addAll(llist2);
			System.out.println("\tAfter LinkedList1.addAll(LinkedList2)");
			System.out.format("LinkedList 1 : %s \n",llist1);
			
			System.out.print("\n\nc) contains function: LinkedList1 contains \"Cherries\" and LinkedList2 contains \"Cherries\": \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			if(llist1.contains("Cherries")) System.out.print("\nFor LinkedList1 true");
			else System.out.print("\nFor LinkedList1 false");
			if(llist2.contains("Cherries")) System.out.print("\tFor LinkedList2 true");
			else System.out.print("\tFor LinkedList2 false");
			
			System.out.print("\n\nd) containsAll function: LinkedList1 contains LinkedList2 and LinkedList1 contains LinkedList3: \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			if(llist1.containsAll(llist2)) System.out.print("\nLinkedList1 containsAll LinkedList2 true");
			else System.out.print("\nLinkedList1 containsAll LinkedList2 false");
			if(llist1.containsAll(llist3)) System.out.print("\tLinkedList1 containsAll LinkedList3 true");
			else System.out.print("\tLinkedList1 containsAll LinkedList3 false");
			
			System.out.print("\n\ne) size function: For LinkedList1 , LinkedList2 , LinkedList3: \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			System.out.format("\nLinkedList 1 size = %d , LinkedList 2 size = %d , LinkedList 3 size = %d", llist1.size(),llist2.size(),llist3.size());

			System.out.print("\n\nf) remove function: remove \"Apple\" to LinkedList1, LinkedList2 and LinkedList3: \n");
			llist1.remove("Apple");
			llist2.remove("Apple");
			llist3.remove("Apple");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			System.out.format("\nLinkedList 1 size = %d , LinkedList 2 size = %d , LinkedList 3 size = %d", llist1.size(),llist2.size(),llist3.size());
			
			System.out.print("\n\ng) retainAll function: Base LinkedList1 Parameter LinkedList3: \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			System.out.format("LinkedList 3 : %s \n",llist3);
			llist1.retainAll(llist3);
			System.out.println("\tAfter LinkedList1.retainAll(LinkedList3)");
			System.out.format("LinkedList 1 : %s \n",llist1);
			
			System.out.print("\n\nh) removeAll function: Base LinkedList2 Parameter LinkedList3: \n");
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			llist2.removeAll(llist3);
			System.out.println("\tAfter LinkedList2.removeAll(LinkedList3)");
			System.out.format("LinkedList 2 : %s \n",llist2);
			
			System.out.print("\n\ni) clear function: LinkedList1 : \n");
			System.out.format("LinkedList 1 : %s \n",llist1);
			llist1.clear();
			System.out.println("\tAfter LinkedList1.clear()");
			System.out.format("LinkedList 1 : %s \n",llist1);
			
			System.out.print("\n\nj) isEmpty function: LinkedList1, LinkedList2 : \n");
			System.out.format("LinkedList 1 : %s    LinkedList 2 : %s ",llist1,llist2);
			if(llist1.isEmpty()) System.out.print("\nLinkedList1 is empty");
			else System.out.print("\nLinkedList1 is not empty");
			if(llist2.isEmpty()) System.out.print("\tLinkedList2 is empty");
			else System.out.print("\tLinkedList2 is not empty");

			System.out.print("\n\nk) element function: LinkedList2, LinkedList3 : \n");
			System.out.format("LinkedList 2 : %s  \nhead value = %s  \nLinkedList 3 : %s \nhead value = %s",llist2,llist2.element(),llist3,llist3.element());
			
			System.out.print("\n\nl) offer function: insert \"Lime\" into LinkedList2, LinkedList3 : \n");
			llist2.offer("Lime");
			llist3.offer("Lime");
			System.out.format("LinkedList 2 : %s \n",llist2);
			System.out.format("LinkedList 3 : %s \n",llist3);
			
			System.out.print("\n\nk) pool function: LinkedList2, LinkedList3 : \n");
			String temp1;
			String temp2;
			try {
				temp1 = llist2.poll();
				temp2 = llist3.poll();
				System.out.format("LinkedList 2 : %s  \nold head value = %s \nnew head value = %s  \n\nLinkedList 3 : %s  \nold head value = %s \nnew head value = %s",llist2,temp1,llist2.element(),llist3,temp2,llist3.element());
			} catch (MyException err) {
				System.out.println(err.getMessage());
			}
			
			System.out.println("\n\n String Integer test successfully completed. \n");
		}
		System.out.println("\n\n Program successfully completed. \n");
		System.out.print("--------------------------------------------");
	}
}
