import 'package:flutter/material.dart';

class ContainerBorda extends StatefulWidget {
  final Widget child;
  final Color color;

  ContainerBorda({@required this.child, this.color = Colors.white});

  @override
  _ContainerBordaState createState() => _ContainerBordaState();
}

class _ContainerBordaState extends State<ContainerBorda> {
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.all(10),
      margin: EdgeInsets.all(15),
      decoration: BoxDecoration(
        color: widget.color,
        border: Border.all(),
        borderRadius: BorderRadius.circular(5),
      ),
      child: widget.child,
    );
  }
}
