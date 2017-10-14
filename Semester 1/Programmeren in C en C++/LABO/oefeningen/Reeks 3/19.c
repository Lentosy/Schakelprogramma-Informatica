main(){
	int i=7, j;
	double d;
	int *ip, *jp, *tp;
	double *dp;
	const int * p1;
	int * const p2 = &i;
	int t[25];
	int k;
	for(k = 0; k < 25; k++){
		t[k] = 10*k;
	}
}

/* 1*/ i = j;    /* j heeft geen waarde, dus nutteloos */
/* 2*/ jp = &i;  /* OK, jp krijgt adres van i. [jp wijst naar 7] */
/* 3*/ j = *jp;  /* OK, [j wordt 7] */
/* 4*/ *ip = i;  /* Syntactisch juist, maar ip wijst nog nergens aan. je kan de inhoud van 'niets' niet wijzigen */
/* 5*/ ip = jp;  /* OK, het adres dat in jp zit, zal ook het adres worden dat in ip zit. [ip wijst naar 7] */
/* 6*/ &i = ip;  /* Fout, adressen mogen niet aangepast worden */
/* 7*/ (*ip)++;  /* OK, de waarde waar ip naar wijst, verhogen met 1. [i wordt 8] */
/* 8*/ *ip *=i;  /* OK, [i wordt 64] */
/* 9*/ ip++;     /* Syntactisch juist, maar je weet niet wat het volgende adres is, dus nutteloos */
/*10*/ tp = t+2; /* OK, tp wijst naar het element op index 2 van de array t*/
/*11*/ j = &t[5] - tp; /* 5 - 2  [j wordt 3]*/
/*12*/ t++;      /* Niet OK, dit is een constante pointer */
/*13*/ (*t)++;   /* OK. [Element op index 0 van array t wordt 1]*/
/*14*/ *tp--;    /* OK, maar heeft geen nut */
/*15*/ j = (*tp)++; /* OK [j wordt de waarde van element op index 3 van de array t]*/
/*16*/ i = *tp++; /* OK [i wordt 21 en tp wijst naar element op index 3 van de array t] */
/*17*/ p1 = ip;   /* OK */
/*18*/ jp = p1;   /* Niet OK */
/*19*/ (*p1)--;   /* Niet OK, p1 is een pointer naar een const, dus p1 mag niet aan zijn inhoud veranderen */
/*20*/ dp = &i;   /* Niet OK, verschillende types */
/*21*/ dp = ip;   /* Niet OK, verschillende types */
/*22*/ jp = p2;   /* OK, gewone pointer gelijkstellen aan iets dat constant is */
/*23*/ p2 = p1;   /* Niet OK, p2 is const pointer, mag niet verzet worden */
/*24*/ *p2 += i;  /* OK, i wordt 42 */
