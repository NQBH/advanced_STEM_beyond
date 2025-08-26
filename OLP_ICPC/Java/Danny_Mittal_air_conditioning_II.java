import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class AirConditioningII {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tokenizer = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(tokenizer.nextToken());
		int m = Integer.parseInt(tokenizer.nextToken());
		CowInterval[] cowIntervals = new CowInterval[n];
		for (int j = 0; j < n; ++j) {
			tokenizer = new StringTokenizer(in.readLine());
			int from = Integer.parseInt(tokenizer.nextToken());
			int to = Integer.parseInt(tokenizer.nextToken());
			int requiredCoolness = Integer.parseInt(tokenizer.nextToken());
			cowIntervals[j] = new CowInterval(from, to, requiredCoolness);
		}
		AirConditioner[] airConditioners = new AirConditioner[m];
		for (int j = 0; j < m; ++j) {
			tokenizer = new StringTokenizer(in.readLine());
			int from = Integer.parseInt(tokenizer.nextToken());
			int to = Integer.parseInt(tokenizer.nextToken());
			int power = Integer.parseInt(tokenizer.nextToken());
			int money = Integer.parseInt(tokenizer.nextToken());
			airConditioners[j] = new AirConditioner(from, to, power, money);
		}
		int answer = m * 1000;
		for (int mask = 0; mask < 1 << m; ++mask) {
			int[] numberLine = new int[101];
			int totalCost = 0;
			for (int j = 0; j < m; ++j)
				if ((mask & (1 << j)) != 0) {
					totalCost += airConditioners[j].money;
					AirConditioner airConditioner = airConditioners[j];
					for (int x = airConditioner.from; x <= airConditioner.to; ++x)
						numberLine[x] += airConditioner.power;
				}
			boolean works = true;
			for (int j = 0; j < n; ++j) {
				CowInterval cowInterval = cowIntervals[j];
				for (int x = cowInterval.from; x <= cowInterval.to; ++x)
					if (numberLine[x] < cowInterval.requiredCoolness) works = false;
			}
			if (works) answer = Math.min(answer, totalCost);
		}
		System.out.println(answer);
	}

	static class CowInterval {
		final int from;
		final int to;
		final int requiredCoolness;
		CowInterval(int from, int to, int requiredCoolness) {
			this.from = from;
			this.to = to;
			this.requiredCoolness = requiredCoolness;
		}
	}

	static class AirConditioner {
		final int from;
		final int to;
		final int power;
		final int money;
		public AirConditioner(int from, int to, int power, int money) {
			this.from = from;
			this.to = to;
			this.power = power;
			this.money = money;
		}
	}
}