import java.io.*;
import java.util.*;

public class Occurrences {
	public static void main(String args[]) {
		FileReader fr = null;
		BufferedReader br = null;

		ArrayList<String> words = null;
		ArrayList<Integer> count = null;

		try {
			fr = new FileReader("file.txt");
			br = new BufferedReader(fr);

			words = new ArrayList<>();
			count = new ArrayList<>();

			String line;

			while ((line = br.readLine()) != null) {
				String[] tokens = line.split("\\s+");

				for (String word : tokens) {
					int index = words.indexOf(word);

					if (index != -1) {
						count.set(index, count.get(index) + 1);
					} else {
						words.add(word);
						count.add(1);
					}
				}

			}

			br.close();
			fr.close();

			System.out.println("Top 5 most frequent words");

			for (int i = 0; i < Math.min(5, count.size()); i++) {
				int max = i;
				for (int j = i + 1; j < count.size(); j++) {
					if (count.get(max) < count.get(j)) {
						max = j;
					}
				}
				System.out.println(words.get(max) + ": " + count.get(max));
				words.remove(max);
				count.remove(max);
			}

		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}
}