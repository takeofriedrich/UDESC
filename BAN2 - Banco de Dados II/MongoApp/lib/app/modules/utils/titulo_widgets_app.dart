import 'package:flutter/material.dart';

class TituloWidgetsApp extends StatelessWidget {
  final String titulo;
  TituloWidgetsApp({@required this.titulo});
  @override
  Widget build(BuildContext context) {
    return Row(
      children: [
        Text(
          titulo,
          style: TextStyle(
            fontSize: 20,
            fontWeight: FontWeight.bold,
          ),
        ),
      ],
    );
  }
}
