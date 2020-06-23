#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int supply(int* first, int* n_card, int* y_card, int* picture) {
    

    int temp, pic_check;   //�׸�üũ (1�̸� �׸�, 0�̸� �׸�����)

    while (1) {      //�ߺ�üũ �ϸ鼭 ����, �׸�����
        *first = (rand() % 10) + 1; pic_check = rand() % 2;
        temp = *first;

        if (n_card[temp] == 1 || y_card[temp] == 1) {
            continue;
        }
        else {
            break;
        }
    }

    if (pic_check == 1) {   //�ߺ����� (�׸��ִ°�)
        y_card[temp] = 1;
        *picture = 1;
    }

    else {               //�ߺ����� (�׸����°�)
        n_card[temp] = 1;
        *picture = 0;
    }
}



const char* jokbo(int card1, int card1_pic, int card2, int card2_pic) {   //�������ϱ�
    
    char* ttang;

    if ((card1 == 3 && card2 == 8) || (card1 == 8 && card2 == 3) &&
        (card1_pic == 1 && card2_pic == 1)) {
        return "38����";
    }

    else if ((card1 == 1 && card2 == 3) || (card1 == 3 && card2 == 1) &&
        (card1_pic == 1 && card2_pic == 1)) {
        return "����";
    }

    else if ((card1 == 1 && card2 == 8) || (card1 == 8 && card2 == 1) &&
        (card1_pic == 1 && card2_pic == 1)) {
        return "����";
    }
    
    else if (card1 == 10 && card1 == card2) {
        return "�嶯";
    }

    else if (card1 == card2) {
        return ("%d��"),card1;
    }

    else if ((card1 == 1 && card2 == 2) || (card1 == 2 && card2 == 1)) {
        return "�˸�";
    }

    else if ((card1 == 1 && card2 == 4) || (card1 == 4 && card2 == 1)) {
        return "����";
    }

    else if ((card1 == 1 && card2 == 9) || (card1 == 9 && card2 == 1)) {
        return "����";
    }

    else if ((card1 == 1 && card2 == 10) || (card1 == 10 && card2 == 1)) {
        return "���";
    }

    else if ((card1 == 4 && card2 == 10) || (card1 == 10 && card2 == 4)) {
        return "���";
    }

    else if ((card1 == 4 && card2 == 6) || (card1 == 6 && card2 == 4)) {
        return "����";
    }
    else {
        int sum = card1 + card2;
        if (sum >=10) {
            if (sum % 10 == 0) {
                return"����";
            }
            else {
                return ("%d��", sum % 10);
            }
        }
        else {
            return ("%d��", sum);
        }
    }

}

int main() {
    srand(time(NULL)); 
    char* testString = "����";
    int n_card[10] = { 0, };   //�׸� ���� ī��
    int y_card[10] = { 0, };   //�׸� �ִ� ī��

    int A_card_1, A_card_2, A_picture_1, A_picture_2; // �� ī��, �׸����� (0�̸� �׸�����, 1�̸� �׸�)
    int B_card_1, B_card_2, B_picture_1, B_picture_2; // ��� ī��


    printf("������ ī�� ������...\n");
    Sleep(1500);
    supply(&A_card_1, &n_card, &y_card, &A_picture_1);
    supply(&A_card_2, &n_card, &y_card, &A_picture_2);

    printf("��뿡�� ī�� ������...\n");
    Sleep(1500);
    supply(&B_card_1, &n_card, &y_card, &B_picture_1);
    supply(&B_card_2, &n_card, &y_card, &B_picture_2);

    printf("��ī�� : %d (�׸����� : %d) , %d (�׸����� : %d)\n", A_card_1, A_picture_1, A_card_2, A_picture_2);
    printf("��ī�� : %d (�׸����� : %d) , ?\n", B_card_1, B_picture_1);
    printf("���� // �׸������� 0�̸� �׸��� ���ٴ� �ǹ��Դϴ�.\n");

    const char* my_jok, *enemy_jok;
    my_jok = jokbo(A_card_1, A_picture_1, A_card_2, A_picture_2);
    enemy_jok = jokbo(B_card_1, B_picture_1, B_card_2, B_picture_2);
        
    printf("�� ���� : %s\n ���� ���� : %s\n", my_jok, enemy_jok);
}