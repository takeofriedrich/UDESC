import 'package:flutter/material.dart';

class TextosWidgetApp extends StatelessWidget {
  final String texto;
  TextosWidgetApp({@required this.texto});
  @override
  Widget build(BuildContext context) {
    return Row(
      children: [
        Text(
          texto,
          style: TextStyle(
            fontSize: 17,
          ),
        ),
      ],
    );
  }
}
