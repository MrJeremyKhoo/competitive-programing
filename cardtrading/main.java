import java.util.*;
import java.lang.*;
import java.io.*;
//help from competitive programming book website... suggestion to use a greedy approach https://cpbook.net/methodstosolve
//Bing Sen reminded the use of Long over Integer because price can over glow
public class main {
	

	static long profit;
	static class SortBySum implements Comparator<ArrayList<Long>> {
		public int compare(ArrayList<Long> a, ArrayList<Long> b) {
			if((a.get(0) + a.get(1)) < (b.get(0) + b.get(1))) {
				return -1;
			} else if ((a.get(0) + a.get(1)) < (b.get(0) + b.get(1))) {
				return 1;
			} else {
				return 0;
		
			}
		}
	}


	public static void main(String [] args) throws IOException {
	BufferedReader br = new BufferedReader(
			    new InputStreamReader(System.in)); //use buffer reader instead of scanf because I'm cool
	
	//N - number of cards
	//T - Types
	//K - number of pairs
	StringTokenizer NTK = new StringTokenizer(br.readLine());

	int N = Integer.parseInt(NTK.nextToken());	//to count how many lines we are to take in
	int T = Integer.parseInt(NTK.nextToken());	//to count how many lines we are to take in
	int K = Integer.parseInt(NTK.nextToken());	//to count how many lines we are to take in
	
	//make histogram of cards
	int[] cardHist = new int[1000001];
	if(N != 0) {
		StringTokenizer cardTypes = new StringTokenizer(br.readLine());
	
	for (int i = 0; i < N; i++) {
		int cardType = Integer.parseInt(cardTypes.nextToken());
		cardHist[cardType - 1]++; //-1 here to zero the first type of card to index 0	
	}
	}
	//make array that hold buyprice and sellprice pairs
	ArrayList<ArrayList<Long>> buySell = new ArrayList<>();
	for(int i = 0; i < T; i++) {
		StringTokenizer cardPrice = new StringTokenizer(br.readLine());
		long buy = Long.parseLong(cardPrice.nextToken());
		long sell = Long.parseLong(cardPrice.nextToken());
		ArrayList<Long> buySellPair = new ArrayList<>();
		buySellPair.add(Math.max((2-cardHist[i])*buy,0));
		buySellPair.add(cardHist[i]*sell);
		buySell.add(buySellPair);
			
	}
	//Sort based sum of buy and sell price
	Collections.sort(buySell, new SortBySum());
	//buy the pairs
	for(int i = 0; i < K; i++) {
		profit -= buySell.get(i).get(0);
	}
	//sell the leftovers
	for(int i = K; i < T; i++) {
		profit += buySell.get(i).get(1);
	}

		System.out.print(profit);
	}
}
