import 'package:flutter/material.dart';

class CaixaInput extends StatelessWidget {
  final TextEditingController controller;
  final bool password;
  final String hint;
  TextFormField form;
  CaixaInput(
      {@required this.controller,
      @required this.password,
      @required this.hint});

  @override
  Widget build(BuildContext context) {
    return TextFormField(
      controller: controller,
      enableSuggestions: false,
      autocorrect: false,
      obscureText: password,
      decoration: InputDecoration(
        filled: true,
        fillColor: Colors.white,
        hintText: hint,
        focusedBorder: OutlineInputBorder(
          borderSide: BorderSide(color: Colors.white),
          borderRadius: BorderRadius.circular(20),
        ),
        enabledBorder: UnderlineInputBorder(
          borderSide: BorderSide(color: Colors.white),
          borderRadius: BorderRadius.circular(20),
        ),
      ),
      style: TextStyle(
        backgroundColor: Colors.white,
      ),
    );
  }
}
