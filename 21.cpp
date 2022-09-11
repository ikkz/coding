#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"
#include <doctest.h>
#include <numeric>
#include <vector>

constexpr int MAXV = 100;

typedef struct {
  int numVertices, numEdges;
  char VerticesList[MAXV];
  int Edge[MAXV][MAXV];
} MGraph;

int solve(MGraph graph) {
  // 度为奇数的顶点个数
  int num = 0;
  for (size_t i = 0; i < graph.numVertices; i++) {
    int count = 0;
    for (size_t j = 0; j < graph.numVertices; j++) {
      if (graph.Edge[i][j]) {
        count++;
      }
    }
    if (count % 2 == 1) {
      num++;
    }
  }
  return num <= 2 && num % 2 == 0 ? 1 : 0;
}

TEST_CASE("21") {
  MGraph graph;
  int edge[5][5] = {
      {0, 1, 1, 1, 0}, {1, 0, 1, 1, 1}, {1, 1, 0, 1, 0}, {0, 1, 0, 1, 0}};

  graph.numEdges = 8;
  graph.numVertices = 5;
  for (size_t i = 0; i < graph.numVertices; i++) {
    for (size_t j = 0; j < graph.numVertices; j++) {
      graph.Edge[i][j] = edge[i][j];
    }
  }
  CHECK_EQ(solve(graph), 1);

  // 删去一条边
  graph.numEdges--;
  graph.Edge[1][4] = 0;
  graph.Edge[4][1] = 0;
  CHECK_EQ(solve(graph), 0);
}