#include <stdio.h>
#include <string.h>

char odhackuj(char znak) {
	char hekry[] = "áčďěéíňóřšťúůýž";
	char nohekry[] = "acdeeinorstuuyz";
	char hacky[] = "ÁČĎĚÉÍŇÓŘŠŤÚŮÝŽ";
	char nohacky[] = "ACDEEINORSTUUYZ";

	for (int i = 0; i<strlen(hekry); i++) {
		if (znak == hekry[i]) {
			znak = nohekry[i];
			if (znak == hacky[i]) {
				znak = nohacky[i];
			}
							  }
										  }

	return znak;
}

void caesar(char* retezec, int posun) {
	for (int i = 0; i < strlen(retezec); i++) {
		retezec[i] = odhackuj(retezec[i]);
		if (retezec[i] >= 'a' && retezec[i] <= 'z' ||
			retezec[i] >= 'A' && retezec[i] <= 'Z') {
			retezec[i] += posun;
		}
		 if (!(retezec[i] >= 'a' && retezec[i] <= 'z' ||
			retezec[i] >= 'A' && retezec[i] <= 'Z')) {
			 if (posun > 0) { retezec[i] += posun - 26;} 
			 else { retezec[i] += posun + 26; }
		}
	}
}

int main()
{
	char vstup[] = "hulím pívo a píju brčko";
	int posun = 4;

	printf("puvodni zprava: %s\n", vstup);
	caesar(vstup, posun);
	printf("zakodovana zprava:%s", vstup);
	caesar(vstup, -posun);
	printf("dekodovana zprava: %s\n", vstup);
}