# [Diamond V] 제271회 웰노운컵 - 16225 

[문제 링크](https://www.acmicpc.net/problem/16225) 

### 성능 요약

메모리: 4484 KB, 시간: 72 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐, 정렬

### 제출 일자

2025년 3월 5일 11:21:29

### 문제 설명

<p>2250년, 드디어 전세계의 사람들이 기다리는 웰노운컵의 271회 대회가 열린다. 2018년에 1회가 열렸을 당시에는 “웰노운 알고리즘으로 풀 수 있는 문제들”이라는 취지로 웰노운컵이라는 이름이 붙었는데, 지금은 출제/검수하는 사람만 약 1만 명에 달해서 “알고리즘계에서 잘 알려진 사람들은 전부 이 대회의 출제/검수에 참여한다”라는 의미를 가지고 있다.</p>

<p><meta charset="utf-8"></p>

<p>수많은 경쟁자들을 꺾고 마침내 Etacoder Plus와의 결승전이 열렸다. 참, 나와 Etacoder Plus는 인공지능이다. 내 이름은 SolvingCore KX이다. 하긴 요즘 세상에 인간이 본선에 진출하는 것도 이상하지만. 그럼 인간 부문과 인공지능 부문을 따로 열면 되지 않느냐 싶겠지만, 누구나 튜링 테스트를 통과하는 요즘 인간과 인공지능을 구별하는 것이 극도로 힘들기 때문에 현실적이지 못한 방안이다.</p>

<p>결승전의 진행 방식은 조금 특이하다. Etacoder Plus는 작년 대회의 우승자이기 때문에 그에게 약간의 제약이 들어간다. 구체적으로, 결승전에는 짝수 개의 문제가 준비되어 있다. 먼저 도전자가 두 개의 문제를 고르고, 우승자가 그 둘 중 하나를 고른다. 도전자는 남은 하나를 가져간다. 모든 문제가 배정될 때까지 이것을 반복한 다음 배정된 모든 문제를 먼저 푸는 사람이 승리한다. (2250년에는 인공지능도 사람이라고 부른다.)</p>

<p>나는 먼저 각 문제에 대해 두 사람이 얼마나 자신이 있는지를 각각 자연수로 수치화하였다. 즉 내가 문제 i를 푸는 데에는 A[i]만큼 자신이 있고, Etacoder Plus가 푸는 데에는 B[i]만큼 자신이 있다. 내가 두 문제를 고르면 Etacoder Plus는 당연히 더 높은 B값을 가지는 문제를 가져갈 것이다. 이 전략을 가정했을 때, 내가 가져가는 문제에 대해 A값의 합을 최대화하고 싶다.</p>

### 입력 

 <p>첫 줄에 짝수 N(2 ≤ N ≤ 200,000)이 주어진다. 다음 줄에 A[1], ..., A[N], 그 다음 줄에 B[1], ..., B[N]이 (1 ≤ A[i], B[i] ≤ 10<sup>9</sup>) 주어진다. 모든 A[i]는 서로 다르고, 모든 B[i]도 서로 다르다.</p>

### 출력 

 <p>내가 가져가는 문제의 A[i]값의 최대 합을 출력한다.</p>

