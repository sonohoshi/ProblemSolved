using System;
using System.Linq;

namespace CSConsole
{
    class Program
    {
        private static readonly string[] list =
        {
            "선택정렬",
            "삽입정렬",
            "버블정렬",
            "퀵정렬",
            "병합정렬",
            "해시",
            "스택",
            "큐",
            "힙",
            "그리디",
            "그래프",
            "DP",
            "이진탐색",
            "완전탐색",
            "BFS",
            "DFS"
        };

        static void Main(string[] args)
        {
            string[,] student = new string[4, 20];

            for (int i = 0; i < 4; i++)
            {
                string[] shuffled = list.OrderBy(str => Guid.NewGuid()).ToArray();
                for (int j = 0; j < 20; j++)
                {
                    bool isChecked = true;
                    if (j < 16)
                    {
                        student[i, j] = shuffled[j];
                    }
                    else
                    {
                        student[i, j] = list[j - 16 + 4 * i];
                    }

                    for (int k = 0; k < i; k++)
                    {
                        if (student[k, j].Equals(student[i, j])) isChecked = false;
                    }

                    if (!isChecked)
                    {
                        i--;
                        break;
                    }
                }
            }

            for (int i = 0; i < 20; i++)
            {
                Console.Write(i + 1 + " : ");
                for (int j = 0; j < 4; j++)
                {
                    Console.Write(student[j,i] + " ");
                }

                Console.WriteLine();
            }
        }
    }
}