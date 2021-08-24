import 'package:flutter/material.dart';
import 'package:molhei_o_pe/app/modules/utils/consts.dart';

class BarraLogo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.only(top: 25),
      width: MediaQuery.of(context).size.width / 2,
      height: 60,
      child: Center(
        child: Image.asset('images/logo.png'),
      ),
      decoration: BoxDecoration(
        color: ROXO_APP,
        border: Border.all(color: Colors.white, width: 3),
        borderRadius: BorderRadius.circular(25),
      ),
    );
  }
}
