#include <iostream>
using namespace std;

int act(int x) {
	if (x < 0.5) return 0;
	return 1;
}

int go(int money, int toxic, int location) {
	int x[3] = { money, toxic, location };
	const float DEEP_NEURAL_SL1_1[3] = { 0.3, 0.3, 0 };
	const float DEEP_NEURAL_SL1_2[3] = { 0.8, -0.1, 0.4 };

	/* Матрица */
	const float WEIGHT_1[2][3] = {
		{ DEEP_NEURAL_SL1_1[0], DEEP_NEURAL_SL1_1[1], DEEP_NEURAL_SL1_1[2] },
		{ DEEP_NEURAL_SL1_2[0], DEEP_NEURAL_SL1_2[1], DEEP_NEURAL_SL1_2[2] }
	};

	/* Вектор */
	const int WEIGHT_2[2] = { -1, 1 };

	float SUM_HIDDEN_1 = WEIGHT_1[0][0] * x[0] + WEIGHT_1[0][1] * x[1] + WEIGHT_1[0][2] * x[2];
	float SUM_HIDDEN_2 = WEIGHT_1[1][0] * x[0] + WEIGHT_1[1][1] * x[1] + WEIGHT_1[1][2] * x[2];

	/* Значние сумм скрытых нейронов */
	const float SUM_HIDDEN_RESULT[2] = { SUM_HIDDEN_1, SUM_HIDDEN_2 };

	/* Результат скрытых нейронов */
	int RESULT_HIDDEN[2] = {
		act(SUM_HIDDEN_RESULT[0]),
		act(SUM_HIDDEN_RESULT[1])
	};

	int RESULT_END = act(WEIGHT_2[0] * RESULT_HIDDEN[0] + WEIGHT_2[1] * RESULT_HIDDEN[1]);

	return RESULT_END;
}

int main() {
	setlocale(LC_ALL, "ru");

	int money, toxic, location;
	cout << "Большая зарплата? (0, 1)\n";
	cin >> money;
	cout << "Токсичная команда? (0, 1)\n";
	cin >> toxic;
	cout << "Удобно ли Вам ездить в офис? (0, 1)\n";
	cin >> location;

	if (go(money, toxic, location) == 1) cout << "Можете устраиваться!";
	else cout << "Вам следует поискать еще вакансии...";
}