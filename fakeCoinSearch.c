#include <stdio.h>
#include <stdlib.h>

// ��¥ ������ ã�� �Լ�
int findFakeCoin(int left, int right, int coins[]) {

	// ���￡ ������ �÷��� ���� ������ ������ ����
	int sumLeft = 0, sumRight = 0;
	int mid = (left + right) / 2;

	for (int i = left; i <= mid; i++) {
		sumLeft += coins[i];
	}

	for (int i = mid + 1; i <= right; i++) {
		sumRight += coins[i];
	}

	if (sumLeft < sumRight) {
		// ������ ������ ���ſ�
		if (left == right - 1) {
			// ��¥ ������ ã��
			return right;
		}
		// ������ ���￡�� ��¥ ������ ã��
		return findFakeCoin(mid + 1, right, coins);
	}
	else if (sumLeft > sumRight) {
		// ���� ������ ���ſ�
		if (left == right - 1) {
			// ��¥ ������ ã��
			return left;
		}
		// ���� ���￡�� ��¥ ������ ã��
		return findFakeCoin(left, mid, coins);
	}
	else {
		// ������ �̷�
		if (left == right - 1) {
			// ��¥ ������ ã��
			return -1; // ��¥ ������ ���� ��츦 -1�� ó��
		}
		// ���� ���￡�� ��¥ ������ ã��
		return findFakeCoin(mid + 1, right, coins);
	}
}

int main() {
	int n;
	int fake;

	printf("������ ������ �Է��ϼ���: ");
	scanf_s("%d", &n);
	int* coins = (int*)malloc(sizeof(int) * n); // ���� �޸� �Ҵ�

	for (int i = 0; i < n; i++) {
		printf("%d�� ������ ���Ը� �Է��ϼ���: ", i + 1);
		scanf_s("%d", &coins[i]);
	}

	fake = findFakeCoin(0, n - 1, coins);
	if (fake == -1) {
		printf("��¥ ������ �����ϴ�.\n");
	}

	else {
		printf("��¥ ������ %d��° �����Դϴ�.\n", fake + 1);
	}

	free(coins); // ���� �޸� ����

	return 0;
}
