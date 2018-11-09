//X(#WAIT > 1);
//#WAIT = []
//G(true -> (#WAIT > 0));
//G WAIT || G PING;
//G (WAIT => G PING);
//WAIT => G PING;
//( WAIT => G PING );
//WAIT => G((#DONE >= 1) & (#WAIT > 0));
//G (WAIT => G(~PING));
//G (WAIT => G(~PING));
// G (WAIT => G ~PING);
//G X WAIT;
//
//G (WAIT => G(~PING));
//#PING + #DONE + #WAIT = [];
//#PING + #DONE + #WAIT < [];
// #PING + #DONE >= 2;
//G(PING => G);
//X(#WAIT > 1);
//G (WAIT => G(~DONE));
WAIT U PING;