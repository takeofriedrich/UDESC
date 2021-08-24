import 'package:flutter/material.dart';

class BotaoApp extends StatelessWidget {
  final void Function() onPressed;
  final String text;

  BotaoApp({@required this.text, @required this.onPressed});

  @override
  Widget build(BuildContext context) {
    return Container(
      child: RaisedButton(
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(100),
          side: BorderSide(color: Colors.black),
        ),
        onPressed: onPressed,
        child: Container(
          child: Text(text),
        ),
        color: Colors.white,
      ),
    );
  }
}
