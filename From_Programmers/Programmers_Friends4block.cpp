#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool canDestroy = true;
    bool isDestroyed[30][30] = { false };

    while (canDestroy) {
        canDestroy = false;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if ((board[i].at(j) == board[i].at(j + 1)) && 
                    (board[i + 1].at(j) == board[i + 1].at(j + 1)) && 
                    (board[i + 1].at(j) == board[i].at(j + 1)) && 
                    board[i].at(j) != '0') {
                    for (int x = i; x < i + 2; x++) {
                        for (int y = j; y < j + 2; y++) {
                            if (!isDestroyed[x][y]) {
                                isDestroyed[x][y] = true;
                                answer++;
                            }
                        }
                    }
                    canDestroy = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = m - 1; j >= 0; j--) { 
                if (isDestroyed[j][i]) {
                    cur = j;
                    while (isDestroyed[j][i] && j >= 0) {
                        isDestroyed[j][i] = false;
                        board[j].replace(i, 1, "0");
                        j--;
                    }
                    for (int k = j; k >= 0 && board[cur].at(i) == '0' && cur >= 0 && board[k].at(i) != '0'; k--) {
                        if (isDestroyed[k][i]) {
                            isDestroyed[k][i] = false;
                            board[k].replace(i, 1, "0");
                            continue;
                        }
                        string replace = "";
                        replace += board[k].at(i);
                        board[k].replace(i, 1, "0");
                        board[cur].replace(i, 1, replace);
                        isDestroyed[cur--][i] = false;
                        isDestroyed[k][i] = false;
                    }
                }
            }
        }
        canDestroy = canDestroy;
    }
    return answer;
}

int main() {
    vector<string> board;
    board.push_back("AA");
    board.push_back("AA");
    board.push_back("CC");
    board.push_back("AA");
    board.push_back("AA");
    board.push_back("DD");
    //board.push_back("RRRFCC");
    //board.push_back("TRRRAA");
    //board.push_back("TTMMMF");
    //board.push_back("TMMTTJ");
    /*AAAAA,AUUUA,AUUAA,AAAAA*/
    cout << solution(board.size(), 2, board) << endl;
}

// https://programmers.co.kr/learn/courses/30/lessons/17679

/*
Ǯ �� Ȯ���ؾ� �ϴ� ����

1. �迭 ��Ʈ�Ӹ��� �ִ� �� Ž�� �� out of range ���� �ʵ���
2. ��� ���Ű� ���������� �� �Ǵ���
3. ����� �Ʒ��� �� ����������, �����ؾ��ϴ� ����� �����ͼ� �ߺ� ���ŵ����� �ʴ��� Ȯ��
*/