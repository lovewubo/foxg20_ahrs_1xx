clear all
clc
trun=0.01;
q1_vect= [-500:100:500]';
q2_vect= [-500:100:500]';
j_matrix=[];

for i=1:length(q1_vect);
    for j=1:length(q2_vect);
        q1=q1_vect(i);
        q2=q2_vect(j);
        sim('EKF_test')
        i_start=1;
        i_finish=length(time)-100;
        j1=[];
        j2=[];
        j3=[];
        for k=i_start:1:i_finish
            j1(k)=innova(k,:)*innova(k+1,:)';
            j2(k)=innova(k,:)*innova(k,:)';
            j3(k)=innova(k+1,:)*innova(k+1,:)';
        end
     jp=abs(sum(j1)*(sum(j2)*sum(j3))^(-0.5));
     j_matrix(i,j)=jp;
    end
end  
surf(q1_vect,q2_vect,j_matrix)
            