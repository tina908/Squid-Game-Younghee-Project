#define X 0 //쉼표
#define C 1 //도
#define D 2 //레
#define E 3 //미
#define F 4 //파
#define G 5 //솔
#define A 6 //라
#define B 7 //시
#define TC 8 //높은 도
#define TD 9 //높은 레

#define Warning 7 //경고등
#define Red 6 //빨간불
#define Green 5 //초록불
#define DX 10 //음계 스피커
#define PIR 13 //적외선 감지 센서

//fq함수: 도레미 음계 주파수
int fq[]={0,262,294,330,349,392,440,494,};
//mo함수: 초록불이 들어올 때 효과음
int mo[15][2]={{E,500},{A,500},{A,500},{X,500},
  			   {A,500},{X,500},{G,500},{X,500},
  			   {A,500},{A,500},{E,500},{E,500},
			   {G,500},{X,500}};
//mo함수: 경고등이 들어올 때 효과음
int mo2[6][2]={{TD,500},{TC,500},{TD,500},{TC,500},{TD,500},{TC,500}};

int mtime1 = 100;
int mtime2 = 500;

void setup()
{
  pinMode(PIR, INPUT);
  pinMode(Warning, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
}
 
void loop()
{
  digitalWrite(Warning, LOW);
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
 
  int mtime = random(mtime1, mtime2); //초록불이 켜지는 기간을 랜덤으로 결정
  
  for(int i=0; i<15; i++){ //움직여도 감지 되지 않는 구간
    digitalWrite(Warning, LOW);
  	digitalWrite(Red, LOW);
    digitalWrite(Green, HIGH); //초록불이 켜진 상태
    tone(DX,fq[mo[i][0]],mo[i][1]); //초록불 효과음이 나온다
    delay(mtime); //효과음 속도가 랜덤으로 결정된다
  }
  delay (300);
  
  digitalWrite(Green, LOW);
  digitalWrite(Red, HIGH); //빨간 불이 켜진상태
  mtime = random(mtime1, mtime2) * 30; //빨간불이 켜지는 기간을 랜덤으로 결정
  for(int i=0; i<=mtime; i++){
  	int move = digitalRead(PIR); //움직임이 감지 되는 구간
  	delay(1);
  	if (move == HIGH){ //움직임이 감지 되었을 때
  		for(int i=0; i<7; i++){
    		digitalWrite(Warning, HIGH); //경고불이 들어온다
    		tone(DX,fq[mo2[i][0]],mo[i][1]); //경고음이 나온다
    		delay(20);
  		}
    i=2500;//for문을 빠져나간다
  	}
  }
}

        
  