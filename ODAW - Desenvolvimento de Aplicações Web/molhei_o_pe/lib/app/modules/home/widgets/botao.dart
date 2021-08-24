import 'package:flutter/material.dart';

class Botao extends StatelessWidget {
  final void Function() onTap;
  final String text;
  final double margin;
  final bool selected;
  final bool selectedAcima;

  Botao(
      {@required this.onTap,
      @required this.text,
      @required this.margin,
      this.selected = false,
      this.selectedAcima = false});

  @override
  Widget build(BuildContext context) {
    return Container(
      child: InkWell(
        onTap: onTap,
        child: Text(
          text,
          style: TextStyle(
              fontSize: 20,
              color: Colors.white,
              decoration: selected
                  ? TextDecoration.overline
                  : selectedAcima
                      ? TextDecoration.underline
                      : TextDecoration.none),
        ),
      ),
      margin: EdgeInsets.symmetric(horizontal: margin),
    );
  }
}
