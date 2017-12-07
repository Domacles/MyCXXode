package mPrivate;

import java.io.*;
import java.lang.*;
import java.util.*;

@SuppressWarnings("unused")
public class myTest {
	  
    public static <E> void PrintPr(Queue<E> queue){
        while(queue.peek()!=null){
            System.out.print(queue.remove()+" ");//POP
        }
        System.out.println();
    }
    public static void main(String[] args) {
        PriorityQueue<Integer> priorityQueue=new PriorityQueue<Integer>();
        //优先级队列存放整型数字
        Random random=new Random(47);
        for(int i=0;i<10;i++){
            priorityQueue.offer(random.nextInt(i+10));//Push
             
        }
        PrintPr(priorityQueue);
        ////数组
        List<Integer> ints=Arrays.asList(25,22,20,18,14,9,3,1,1,2,3,9,2,5,1,5,25,30,0,10);
        priorityQueue.addAll(ints);
        PrintPr(priorityQueue);
         
        priorityQueue=new PriorityQueue<Integer>(ints.size(),Collections.reverseOrder());
        priorityQueue.addAll(ints);
        PrintPr(priorityQueue);
         
        //优先级队列存放字符
        String fact="UDJKKDJL WSAPLMAD IUJSAA ATHSHJ";
        List<String> list=Arrays.asList(fact.split(""));
        PriorityQueue<String> priorityQueueStrings=new PriorityQueue<String>(list);
        PrintPr(priorityQueueStrings);
         
        priorityQueueStrings=new PriorityQueue<String>(list.size(),Collections.reverseOrder());
        priorityQueueStrings.addAll(list);
        PrintPr(priorityQueueStrings);
         
        //set去重在排序
        Set<Character> set=new HashSet<Character>();
        for(char c:fact.toCharArray()){
            set.add(c);
        }
        PriorityQueue<Character> pQCharacters=new PriorityQueue<Character>(set);
        PrintPr(pQCharacters);
         
         
    }
 
}

/*************
0 1 1 1 1 1 3 5 8 14 
0 1 1 1 2 2 3 3 5 5 9 9 10 14 18 20 22 25 25 30 
30 25 25 22 20 18 14 10 9 9 5 5 3 3 2 2 1 1 1 0 
      A A A A A D D D H H I J J J J K K L L M P S S S T U U W 
W U U T S S S P M L L K K J J J J I H H D D D A A A A A       
  A D H I J K L M P S T U W 

**************/
