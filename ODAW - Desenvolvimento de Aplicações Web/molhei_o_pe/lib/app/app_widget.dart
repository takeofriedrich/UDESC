import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';

class AppWidget extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    FirebaseAuth auth = FirebaseAuth.instance;
    return MaterialApp(
      navigatorKey: Modular.navigatorKey,
      title: 'Molhei o pé',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      initialRoute: '/',
      onGenerateRoute: Modular.generateRoute,
      debugShowCheckedModeBanner: false,
    );
  }
}
