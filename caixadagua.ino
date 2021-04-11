#define G1 A0
#define R1 A1
#define SIRENE A2
#define G2 A3
#define R2 8
#define RESERVA 9

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define IN5 6
#define IN6 7

#define TIME 1000

int baixo_inf;
int medio_inf;
int alto_inf;
int baixo_sup;
int medio_sup;
int alto_sup;
int count1=0;
int count2=0;

void nivel_muito_alto_caixa_inferior(){// VERDE PISCANDO E SIRENE
  digitalWrite(G1,HIGH);
  digitalWrite(R1,LOW);
  digitalWrite(SIRENE, LOW);
  delay(TIME);
  digitalWrite(G1,LOW);
  digitalWrite(SIRENE, HIGH);
}

void nivel_alto_caixa_inferior() {// VERDE ACESSO
  digitalWrite(G1,LOW);
  digitalWrite(R1,LOW);
  digitalWrite(SIRENE, LOW);
}

void nivel_baixo_caixa_inferior(){// VERMELHO ACESSO
  digitalWrite(G1,HIGH);
  digitalWrite(R1,HIGH);
  digitalWrite(SIRENE, LOW);
  delay(TIME);
  digitalWrite(R1,LOW);
  if(count1==5){
      digitalWrite(SIRENE, HIGH);
      count1=0;
  }
}

void nivel_muito_baixo_caixa_inferior(){// VERMELHO PISCANDO E SIRENE
  digitalWrite(G1,HIGH);
  digitalWrite(R1,LOW);
  digitalWrite(SIRENE, LOW);
  delay(TIME);
  digitalWrite(R1,HIGH);
  digitalWrite(SIRENE, HIGH);
}

void nivel_muito_alto_caixa_superior(){// VERDE PISCANDO E SIRENE
  digitalWrite(G2,HIGH);
  digitalWrite(R2,LOW);
  digitalWrite(SIRENE, LOW);
  delay(TIME);
  digitalWrite(G2,LOW);
  digitalWrite(SIRENE, HIGH);
}

void nivel_alto_caixa_superior() {// VERDE ACESSO
  digitalWrite(G2,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(SIRENE, LOW);
}

void nivel_baixo_caixa_superior(){// VERMELHO ACESSO
  digitalWrite(G2,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(SIRENE, LOW);
  delay(TIME);
  digitalWrite(R2,LOW);
  if(count2==5){
      digitalWrite(SIRENE, HIGH);
      count2=0;
  }
}

void nivel_muito_baixo_caixa_superior(){// VERMELHO PISCANDO E SIRENE
  digitalWrite(G2,HIGH);
  digitalWrite(R2,LOW);
  digitalWrite(SIRENE, LOW);
  delay(TIME);
  digitalWrite(R2,HIGH);
  digitalWrite(SIRENE, HIGH);
}

/*
void teste(){
  digitalWrite(G1,LOW);
  digitalWrite(R1,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(R2,LOW);
  delay(TIME/4);
  digitalWrite(G1,HIGH);
  digitalWrite(R1,HIGH);
  digitalWrite(G2,HIGH);
  digitalWrite(R2,HIGH);
}
*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(A6, INPUT);
}

void loop() {
  
  alto_inf = digitalRead(IN1);
  medio_inf = digitalRead(IN2);
  baixo_inf = digitalRead(IN3);
  
  //alto_sup = digitalRead(IN4);
  //medio_sup = digitalRead(IN5);
  //baixo_sup = digitalRead(IN6);
  
  if(digitalRead(A6)== HIGH){
     digitalWrite(G1,HIGH);
     digitalWrite(R1,HIGH);
  }
  
  if(alto_inf == HIGH && 
     medio_inf == HIGH && 
     baixo_inf == HIGH){
      nivel_muito_alto_caixa_inferior();
  }

    if(alto_inf == LOW && 
       medio_inf == HIGH && 
       baixo_inf == HIGH){
        nivel_alto_caixa_inferior();
  }

    if(alto_inf == LOW && 
       medio_inf == LOW && 
       baixo_inf == HIGH){
        nivel_baixo_caixa_inferior();
        count1++;
  }

    if(alto_inf == LOW && 
       medio_inf == LOW && 
       baixo_inf == LOW){
        nivel_muito_baixo_caixa_inferior();
  }
/*
    if(alto_sup == HIGH && 
       medio_sup == HIGH && 
       baixo_sup == HIGH){
      nivel_muito_alto_caixa_superior();
  }

    if(alto_sup == LOW && 
       medio_sup == HIGH && 
       baixo_sup == HIGH){
        nivel_alto_caixa_superior();
  }

    if(alto_sup == LOW && 
       medio_sup == LOW && 
       baixo_sup == HIGH){
        nivel_baixo_caixa_superior();
        count1++;
  }

    if(alto_sup == LOW && 
       medio_sup == LOW && 
       baixo_sup == LOW){
        nivel_muito_baixo_caixa_superior();
  }
   */  
  delay(TIME/4);
}