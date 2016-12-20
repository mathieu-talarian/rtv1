<SCRIPT LANGUAGE=JavaScript>
var pi,q,del,bs
pi=Math.PI;exp=Math.E;            //ligne 10
var x=new Array()
function go()
{
with (Math)
{
a="";b=a;c=a;d=a;e=a;
for(k=0;k<=3;k++) {x[k]=0};
a=prompt("a = ",a)
if (a==null) {return} else {a=eval(a)}
if(a==0) {alert("a ne peut être nul !");return}
b=prompt("b = ",b)
if (b==null) {return} else {b=eval(b)}
c=prompt("c = ",c)
if (c==null) {return} else {c=eval(c)}
d=prompt("d = ",d)
if (d==null) {return} else {d=eval(d)}
e=prompt("e = ",e)
if (e==null) {return} else {e=eval(e)}

bs=b/4/a;                                        //ligne 30
aa=-3*b*b/8/a/a+c/a;
ma=-aa;a$=" + ";if(ma<0){a$=" "}
bb=b*b*b/8/a/a/a-b*c/2/a/a+d/a;
cc=-3*b*b*b*b/256/a/a/a/a+c*b*b/16/a/a/a-b*d/4/a/a+e/a
mc=-4*cc;c$=" + ";if(mc<0){c$=" "}
k=4*aa*cc-bb*bb
k$=" + ";if(k<0){k$=" "}
if(abs(bb)<1e-14){alert("B = 0, l'équation en X est bicarrée");bicar();return}
alert("A = "+aa+"\n"+"B = "+bb+"\n"+"C = "+cc);
alert("Equation résolvante : u^3"+a$+ma+"u^2"+c$+mc+"u"+k$+k+" = 0")              // ligne 40

a=1;b=ma;c=mc;d=k;
//-------------------------------------- résol degré 3
vt=-b/3/a;mvt=-vt;
p=c/a-b*b/3/a/a;
q=b*b*b/a/a/a/13.5+d/a-b*c/3/a/a;
if (abs(p)<1e-14) {p=0};
if (abs(q)<1e-14) {q=0};
del=q*q/4+p*p*p/27;
if (abs(del)<1e-14) {del=0}            // ligne 50
alert("Forme U^3 + pU + q avec u = U - b/3a"+"\n"+"b/3a = "+mvt+"\n"+"p = "+p+" ; q = "+q+"\n"+"delta = "+del)
// -------------------------------------------
if (del<=0)
{
if (p!=0){kos=-q/2/sqrt(-p*p*p/27);r=sqrt(-p/3)} else {kos=0;r=0}   // vu que del<=0, si p=0, alors del=0
if (abs(abs(kos)-1)<1e-14) {alpha=-pi*(kos-1)/2} else {alpha=acos(kos)}
for(k=0;k<=2;k++){x[k]=2*r*cos((alpha+2*k*pi)/3)+vt}
if(r==0){u=x[0];fin();return}
if (x[0]>aa) {u=x[0];fin();return}
u=x[1];if (x[2]>aa) {u=x[2]}                // ligne 60
fin();return
}
// ----------- fin if
else
{
u=uv(1)+uv(-1)+vt;
fin()
} // fin else
} // fin with
} // fin procedure                           //ligne 70

function bicar()
{
with(Math)
{
del=aa*aa-4*cc;
if(del<0){alert("Pas de solutions");return}
del=sqrt(del);
x12=(-aa+del)/2;
x32=(-aa-del)/2;t12=0                                                             //ligne 81
if(x12>=0){x1=sqrt(x12);x2=-x1;x1=x1-bs;x2=x2-bs;alert("x1 = "+x1+"\n"+"x2 = "+x2);t12=1}
if(x32>=0 && t12==1){x3=sqrt(x32);x4=-x3;x3=x3-bs;x4=x4-bs;alert("x3 = "+x3+"\n"+"x4 = "+x4);return}
if(x32>=0){x3=sqrt(x32);x4=-x3;alert("x1 = "+x3+"\n"+"x2 = "+x4);return}
alert("C'est tout !")
return
}
}

function fin()
{
with(Math)                                                                 // ligne 90
{
uma=u-aa;z=bb/2/uma;
alert("z = "+z+" , "+"u - A = "+uma)
d1=uma-4*(z*sqrt(uma)+u/2);t1=0;
if (d1>=0){x1=(sqrt(uma)+sqrt(d1))/2-bs;x2=(sqrt(uma)-sqrt(d1))/2-bs;t1=1}
d2=uma-4*(-z*sqrt(uma)+u/2);t2=0;
if (d2>=0){x3=(-sqrt(uma)+sqrt(d2))/2-bs;x4=(-sqrt(uma)-sqrt(d2))/2-bs;t2=1}
if(t1+t2==0){alert("Pas de solutions");return}
if(t1*t2==0)                                            // ligne 100
{
alert("Deux solutions");
if(t1==1){alert("x1 = "+x1+"\n"+"x2 = "+x2)}
if(t2==1){alert("x1 = "+x3+"\n"+"x2 = "+x4)}
}
else
{
alert("Quatre solutions");
alert("x1 = "+x1+"\n"+"x2 = "+x2)
alert("x3 = "+x3+"\n"+"x4 = "+x4)
} // fin else
} // fin with
} // fin procedure
