//#PING + #DONE + #WAIT = [];
//#PING + #DONE + #WAIT < [];
//X(#WAIT > 1);
//#PING + #DONE > 2;
//#WAIT = []
//G(true -> (#WAIT > 0));
//G WAIT || G PING;
//G (WAIT => G PING);
//WAIT => G PING;
//( WAIT => G PING );
WAIT => G((#DONE >= 1) & (#WAIT > 0));