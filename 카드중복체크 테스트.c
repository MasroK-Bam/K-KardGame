#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int supply(int* first, int* n_card, int* y_card, int* picture) {
    

    int temp, pic_check;   //그림체크 (1이면 그림, 0이면 그림없음)

    while (1) {      //중복체크 하면서 숫자, 그림결정
        *first = (rand() % 10) + 1; pic_check = rand() % 2;
        temp = *first;

        if (n_card[temp] == 1 || y_card[temp] == 1) {
            continue;
        }
        else {
            break;
        }
    }

    if (pic_check == 1) {   //중복방지 (그림있는거)
        y_card[temp] = 1;
        *picture = 1;
    }

    else {               //중복방지 (그림없는거)
        n_card[temp] = 1;
        *picture = 0;
    }
}



const char* jokbo(int card1, int card1_pic, int card2, int card2_pic) {   //족보정하기
    
    char* ttang;

    if ((card1 == 3 && card2 == 8) || (card1 == 8 && card2 == 3) &&
        (card1_pic == 1 && card2_pic == 1)) {
        return "38광땡";
    }

    else if ((card1 == 1 && card2 == 3) || (card1 == 3 && card2 == 1) &&
        (card1_pic == 1 && card2_pic == 1)) {
        return "광땡";
    }

    else if ((card1 == 1 && card2 == 8) || (card1 == 8 && card2 == 1) &&
        (card1_pic == 1 && card2_pic == 1)) {
        return "광땡";
    }
    
    else if (card1 == 10 && card1 == card2) {
        return "장땡";
    }

    else if (card1 == card2) {
        return ("%d땡"),card1;
    }

    else if ((card1 == 1 && card2 == 2) || (card1 == 2 && card2 == 1)) {
        return "알리";
    }

    else if ((card1 == 1 && card2 == 4) || (card1 == 4 && card2 == 1)) {
        return "독사";
    }

    else if ((card1 == 1 && card2 == 9) || (card1 == 9 && card2 == 1)) {
        return "구삥";
    }

    else if ((card1 == 1 && card2 == 10) || (card1 == 10 && card2 == 1)) {
        return "장삥";
    }

    else if ((card1 == 4 && card2 == 10) || (card1 == 10 && card2 == 4)) {
        return "장사";
    }

    else if ((card1 == 4 && card2 == 6) || (card1 == 6 && card2 == 4)) {
        return "세륙";
    }
    else {
        int sum = card1 + card2;
        if (sum >=10) {
            if (sum % 10 == 0) {
                return"망통";
            }
            else {
                return ("%d끗", sum % 10);
            }
        }
        else {
            return ("%d끗", sum);
        }
    }

}

int main() {
    srand(time(NULL)); 
    char* testString = "광땡";
    int n_card[10] = { 0, };   //그림 없는 카드
    int y_card[10] = { 0, };   //그림 있는 카드

    int A_card_1, A_card_2, A_picture_1, A_picture_2; // 내 카드, 그림유무 (0이면 그림없음, 1이면 그림)
    int B_card_1, B_card_2, B_picture_1, B_picture_2; // 상대 카드


    printf("나에게 카드 지급중...\n");
    Sleep(1500);
    supply(&A_card_1, &n_card, &y_card, &A_picture_1);
    supply(&A_card_2, &n_card, &y_card, &A_picture_2);

    printf("상대에게 카드 지급중...\n");
    Sleep(1500);
    supply(&B_card_1, &n_card, &y_card, &B_picture_1);
    supply(&B_card_2, &n_card, &y_card, &B_picture_2);

    printf("내카드 : %d (그림유무 : %d) , %d (그림유무 : %d)\n", A_card_1, A_picture_1, A_card_2, A_picture_2);
    printf("적카드 : %d (그림유무 : %d) , ?\n", B_card_1, B_picture_1);
    printf("도움말 // 그림유무가 0이면 그림이 없다는 의미입니다.\n");

    const char* my_jok, *enemy_jok;
    my_jok = jokbo(A_card_1, A_picture_1, A_card_2, A_picture_2);
    enemy_jok = jokbo(B_card_1, B_picture_1, B_card_2, B_picture_2);
        
    printf("내 족보 : %s\n 상대방 족보 : %s\n", my_jok, enemy_jok);
}