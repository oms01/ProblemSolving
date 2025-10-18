# [Gold V] Bulb Game - 31584 

[문제 링크](https://www.acmicpc.net/problem/31584) 

### 성능 요약

메모리: 1124 KB, 시간: 0 ms

### 분류

애드 혹, 게임 이론

### 제출 일자

2025년 10월 19일 00:08:10

### 문제 설명

<p>친한 친구 민형이와 선율이가 재미있는 게임을 한다. 게임은 아래와 같이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 버튼과 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N-1$</span></mjx-container>개의 전구가 있는 게임판에서 이루어진다. 여기서 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>은 항상 짝수이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6f1ce0e4-af6f-4559-8671-806ad2aa553c/-/preview/" style="height: 132px; width: 800px;"></p>

<p>게임은 민형이와 선율이가 번갈아 버튼을 누르는 방식으로 진행된다. 매 순간마다, 민형이와 선율이는 이때까지 눌리지 않은 버튼 중에서 하나를 골라 누른다. 선율이가 버튼을 누르면 민형이가 방금 전에 눌렀던 버튼과 선율이가 누른 버튼 사이에 있는 모든 전구의 상태가 바뀐다. (꺼져있는 전구는 켜지고, 켜있는 전구는 꺼진다.)</p>

<p>처음에는 모든 전구가 꺼져있다. 이 상태에서 민형이가 2번째 버튼을 누르고 선율이가 4번째 버튼을 누르면 게임판의 상태가 아래와 같이 바뀐다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/205050c4-0d5f-4a04-8312-c9ee92974732/-/preview/" style="height: 132px; width: 800px;"></p>

<p>여기에서 민형이가 3번째 버튼을 누르고 선율이가 5번째 버튼을 누르면 게임판의 상태가 아래와 같이 바뀐다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/11218f95-9161-4929-9220-1633e83f29de/-/preview/" style="height: 132px; width: 800px;"></p>

<p>민형이와 선율이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 버튼을 모두 누르면 게임이 끝난다. 게임이 끝난 후, 켜진 전구가 꺼진 전구보다 더 많으면 선율이가 이기고, 그 이외에는 민형이가 이긴다.</p>

<p>선율이는 게임의 긴장감을 조성하기 위해 진 사람이 민형, 선율 둘을 포함한 16명의 친구들에게 치킨을 쏘겠다는 제안을 했다. 알다시피 16명분의 치킨은 매우 비싸기 때문에 선율이가 게임에서 진다면 기껏 파격적인 제안을 했다가 거액을 내야 하는 대참사가 일어날 수 있다. 선율이가 이길 수 있도록 전략을 짜는 프로그램을 작성하여라. 물론 선율이가 이길 수 있는 전략은 항상 존재한다.</p>

### 입력 

 <p>당신은 게임을 하는 함수 <code>Init(N)</code> 과 <code>MakeTurn(M)</code> 을 작성해야 한다. (<code>Init(N)</code>, <code>MakeTurn(M)</code> 함수는 bulb.c / bulb.cpp에 있다.)</p>

<p><code>void Init(int N)</code> 함수는 맨 처음에 한 번 호출되며, 여기서 전처리 등을 할 수 있다.</p>

<ul>
	<li><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>: 전구의 수 (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>1</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2 \le N \le 1\,000$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>은 짝수)</li>
</ul>

<p><code>int MakeTurn(int M)</code> 함수는 <code>Init</code> 함수가 호출된 후 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-texatom texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2F"></mjx-c></mjx-mo></mjx-texatom><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mrow data-mjx-texclass="ORD"><mo>/</mo></mrow><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N/2$</span></mjx-container>번 호출되며, 당신은 선율이가 눌러야 하는 버튼의 번호를 반환해야 한다.</p>

<ul>
	<li><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>: 민형이가 자신의 턴에 누른 버튼의 번호 (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>M</mi><mo>≤</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le M \le N$</span></mjx-container>)</li>
	<li>반환값: 선율이가 자신의 턴에 눌러야 하는 버튼의 번호 (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le$</span></mjx-container> 반환값 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>≤</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\le N$</span></mjx-container>)</li>
</ul>

<p>만약 게임이 정상적으로 끝나고 선율이가 졌다면 <code>Wrong[1]</code>을 출력한다. <code>MakeTurn(M)</code> 함수의 반환값이 범위를 벗어나거나 이미 눌렀던 버튼의 번호라면 <code>Wrong[2]</code>를 출력하고 프로그램이 즉시 끝난다.</p>

<p>예시 프로그램은 다음과 같다.</p>

<pre style="margin: 0; line-height: 125%"><span style="color: #BC7A00">#include "bulb.h"</span>

<span style="color: #B00040">void</span> <span style="color: #0000FF">Init</span>(<span style="color: #B00040">int</span> N) {
	<span style="color: #408080; font-style: italic">// do nothing</span>
}

<span style="color: #B00040">int</span> <span style="color: #0000FF">MakeTurn</span>(<span style="color: #B00040">int</span> M) {
	<span style="color: #008000; font-weight: bold">return</span> (M<span style="color: #666666">+2</span>)<span style="color: #666666">%7</span>;
}</pre>

<p>메모리 접근, 시스템 호출 등의 비정상적인 방법을 사용하면 오답 처리될 수 있음에 유의하여라.</p>

### 출력 

 Empty

