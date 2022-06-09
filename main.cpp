/*
Author: Jyoti Gurung
Date: 6/8/22
Project: Graph in an adjacency matrix, add and delete data and links.
*/

#include <iostream>

using namespace std;

int main() {

  // "empty" matrix
  int graph[6][6];
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 6; j++){
        graph[i][j] = 0;
    }
  }

  // based on matrix size
  int count = 0;
  
  while (true) {

    if (count == 5) {
      cout << endl << "Adding will not work; delete Vertexes to make up space" << endl;
    }
    
    cout << endl<< "1: Add Vertex, 2: Add Edge, 3: Remove Vertex, 4: Remove Edge, 5: Print" << endl;
    int track;
    cin >> track;

    // 5 things to do based on ints you enter
    switch (track) {
      int input;
      int input2;

      // ADD data; based on count and  use it on the edges or skim of each side of 2d array
      case 1:
        count++;
        cout << "Enter #(no 0): ";
        cin >> input;
        graph[count][0] = input;
        graph[0][count] = input;
        break;
        
        // 2 points based on the # enter first, you linked em up
      case 2:
        cout << "Enter 1st # to connect: ";
        cin >> input;
        cout << "Enter 2nd # to connect: ";
        cin >> input2;

        int a,b;
        
        for(int i = 0; i < 6; i++){
          if (graph[0][i] == input) {
            a = i;
          }
        }
        for(int i = 0; i < 6; i++){
          if (graph[i][0] == input2) {
            b = i;
          }
        }

        graph[b][a] = 1;

        break;

        // try to match the topline, and reverse if for the mirror side to set to 0 and then use the found topline to delete down the ladder
        case 3:
          count--;
          cout << "Enter #(no 0): ";
          cin >> input;
          for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if (graph[i][j] == input) {
                  graph[i][j] = 0;
                  graph[j][i] = 0;
                  for (int a = 0; a < 6; a++) {
                    graph[a][j] = 0;
                  }
                }
            }
          }
          break;

      //reverse of connecting essentially
      case 4:
        cout << "Enter 1st # to disconnect: ";
        cin >> input;
        cout << "Enter 2nd # to disconnect: ";
        cin >> input2;

        int c,d;
        
        for(int i = 0; i < 6; i++){
          if (graph[0][i] == input) {
            c = i;
          }
        }
        for(int i = 0; i < 6; i++){
          if (graph[i][0] == input2) {
            d = i;
          }
        }

        graph[d][c] = 0;
        
        break;

      // go through and print
      case 5:
        for(int i = 0; i < 6; i++){
          for(int j = 0; j < 6; j++){
              cout << graph[i][j] << " ";
          }
          cout << endl;
        }
      
    }
  }
}

/*
      case 3:
        count++;
        cout << "Enter #(no 0): ";
        cin >> input;
        graph[count][0] = input;
        graph[0][count] = input;
        break;
  
      case 4:
        cout << "Enter #: ";
        cin >> input;
        break;
*/
