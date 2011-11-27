H=[];
B=[];
G=[];
h=w(1,:);
hx=magx;
hy=magy;
hz=magz;
for i=1:1:10    %per far si che H abbia almeno 10 elemnti così m>n
    H(i,1)=hx(i)^2;
    H(i,2)=2*hx(i)*hy(i);
    H(i,3)=2*hx(i)*hz(i);
    H(i,4)=hy(i)^2;
    H(i,5)=2*hy(i)*hz(i);
    H(i,6)=hz(i)^2;
    H(i,7)=hx(i);
    H(i,8)=hy(i);
    H(i,9)=hz(i);
    H(i,10)=1;
    Hb(i,1)=hx(i);
    Hb(i,2)=hy(i);
    Hb(i,3)=hz(i);
end
for i=11:1:length(magx)-1 %ora inizia l'algoritmo
    H(i,1)=hx(i)^2;
    H(i,2)=2*hx(i)*hy(i);
    H(i,3)=2*hx(i)*hz(i);
    H(i,4)=hy(i)^2;
    H(i,5)=2*hy(i)*hz(i);
    H(i,6)=hz(i)^2;
    H(i,7)=hx(i);
    H(i,8)=hy(i);
    H(i,9)=hz(i);
    H(i,10)=1;
    HH=H'*H; % uso la notazione dell'articolo e creo HH
    [K,P,L]=svd(HH); %HH è una matrice quadrata da cui k è uguale a L
    gsi_norm=K(:,10); % mi fido dell'articolo e prendo la decima colonna che in effetti è relativa al 10° valore singolare che è il + piccolo
    g1=gsi_norm(1);
    g2=gsi_norm(2);
    g3=gsi_norm(3);
    g4=gsi_norm(4);
    g5=gsi_norm(5);
    g6=gsi_norm(6);
    g7=gsi_norm(7);
    g8=gsi_norm(8);
    g9=gsi_norm(9);
    g10=gsi_norm(10);
    gamma=[g1 g2 g3;g2 g4 g5;g3 g5 g6];
    b=-0.5*inv(gamma)*[g7;g8;g9];
    bx=b(1);
    by=b(2);
    bz=b(3);
    B(i,1)=bx; %creo B per notare una convergenza
    B(i,2)=by;
    B(i,3)=bz;
    gsi_modulo=h*h'*(g1*bx^2+2*g2*bx*by+2*g3*bx*bz+g4*by^2+2*g5*by*bz+2*g6*bz^2-g10)^-1; % credo di poter elevare alla -1 tanto è uno scalare
    gsi=gsi_norm*gsi_modulo;
    g1=gsi(1);
    g2=gsi(2);
    g3=gsi(3);
    g4=gsi(4);
    g5=gsi(5);
    g6=gsi(6);
    g7=gsi(7);
    g8=gsi(8);
    g9=gsi(9);
    g10=gsi(10);
    gamma=[g1 g2 g3;g2 g4 g5;g3 g5 g6];
    [U,A,V]=svd(gamma); %per come è costruita gamma è quadrata e simmetrica da cui U è uguale a V
    G=V*sqrt(A)*V';
    b=[bx;by;bz];
    hm=[hx(i);hy(i);hz(i)];
    hb=G*(hm-b);
    Hb(i,1)=hb(1);
    Hb(i,2)=hb(2);
    Hb(i,3)=hb(3);
    f(i)=norm(hm); %norma del vettore misurato
    j(i)=norm(hb); %norma del vettore calibrato
    k(i)=norm(h);  %norma del vettore reale
   
end
%dovrei notare una convergenza di valori di B, e c'è, anche se i dati raccolti sono su prove fatte quasi statiche... 
figure(1) 
plot(B(:,1)),xlabel('campioni [100Hz]'),ylabel('bias X [Gauss]')
figure(2) 
plot(B(:,2)),xlabel('campioni [100Hz]'),ylabel('bias Y [Gauss]')
figure(3) 
plot(B(:,3)),xlabel('campioni [100Hz]'),ylabel('bias Z [Gauss]')
%stoppando la simulazione a fasi succesive noto come anche i valori della matrice G convergano
figure (4)
hold on
plot(j),xlabel('campioni [100Hz]'),ylabel('[Gauss]')
plot(f,'r')%noto come il valore della norma dopo un transitorio iniziale è più stabile e costante rispetto a quella del dato misurato
plot(k,'g')
legend('norma di h calibrato','norma di h misurato','norma di h vero')
figure (5)
plot(bx)
plot(by)
plot(bz)
hold on
figure (6)
plot3(hx,hy,hz)

plot3(Hb(:,1),Hb(:,2),Hb(:,3),'r')


