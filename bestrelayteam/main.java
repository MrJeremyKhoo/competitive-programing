import java.util.*;
import java.lang.*;
import java.io.*;

public class main {
	static double fastestTime = 99.9;
	static double testTime;
	static LinkedList<String> bestTeam = new LinkedList<>();
	static LinkedList<String> testTeam = new LinkedList<>();
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(
			    	new InputStreamReader(System.in)); //use buffer reader instead of scanf because I'm cool
	//preprocesses
		HashMap<String, Double> flyingStart = new HashMap<>(); //store runner and corresponding times	
		HashMap<String, Double> notFlyingStart = new HashMap<>(); //store runner and corresponding times	

		int numLines = Integer.parseInt(br.readLine());	//to count how many lines we are to take in
		for(int i = 0; i < numLines; i++) {
			// main loop store runner into hashmap
			StringTokenizer st = new StringTokenizer(br.readLine());
			String runnerName = st.nextToken();
			double notFlyingSpeed = Double.parseDouble(st.nextToken());
			double flyingSpeed = Double.parseDouble(st.nextToken());
			notFlyingStart.put(runnerName,notFlyingSpeed);
			flyingStart.put(runnerName,flyingSpeed);
		}
		//sort flyingstart list and bruteforce first leg	
		List<Map.Entry<String, Double>> sortedList = new LinkedList<Map.Entry<String, Double>>(flyingStart.entrySet());

		Collections.sort(sortedList, new Comparator<Map.Entry<String,Double>> () {
			public int compare(Map.Entry<String, Double> o1, Map.Entry<String,Double> o2) {
				return (o1.getValue()).compareTo(o2.getValue());
			}
		});

		HashMap<String, Double> sortedMap = new LinkedHashMap<String,Double>();
		for (Map.Entry<String, Double> entry: sortedList) {
			sortedMap.put(entry.getKey(), entry.getValue());
		}


		//brute force pick first runner and top 3 flying start runner, fastest team is fastest team
		notFlyingStart.forEach(
			(runner, speed)
				-> {testTime = 0.0 + speed;
				testTeam.clear();	
				sortedMap.forEach(
					  (flyingRunner, flyingSpeed) 
					  -> {if(testTeam.size() < 3 && flyingRunner != runner) {
						testTime = testTime + flyingSpeed;
						testTeam.addLast(flyingRunner);
					  }});
			testTeam.addFirst(runner);
			if(testTime < fastestTime) {
				fastestTime = testTime;	
				bestTeam.clear();
				bestTeam.addAll(testTeam);
			}	
			});
		System.out.println(fastestTime);
		bestTeam.forEach(
			(runner)
				-> System.out.println(runner)
		);
	}
}
