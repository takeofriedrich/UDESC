import 'package:app_mobile/app/modules/home/checkin/checkin_module.dart';
import 'package:app_mobile/app/modules/home/cidades/cidades_module.dart';
import 'package:app_mobile/app/modules/home/comprar/comprar_module.dart';
import 'package:app_mobile/app/modules/home/perfil/perfil_page.dart';
import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'home_controller.dart';

class HomePage extends StatefulWidget {
  final String title;
  const HomePage({Key key, this.title = "Home"}) : super(key: key);

  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends ModularState<HomePage, HomeController> {
  //use 'controller' variable to access controller

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: PageView(
        physics: new NeverScrollableScrollPhysics(),
        controller: controller.pageController,
        children: [
          RouterOutlet(module: ComprarModule()),
          RouterOutlet(module: CheckinModule()),
          RouterOutlet(module: CidadesModule()),
          PerfilPage(),
        ],
      ),
      bottomNavigationBar: AnimatedBuilder(
        animation: controller.pageController,
        builder: (BuildContext context, Widget child) {
          return BottomNavigationBar(
            type: BottomNavigationBarType.fixed,
            currentIndex: controller.pageController?.page?.round() ?? 0,
            items: [
              BottomNavigationBarItem(
                icon: Container(
                  height: 35,
                  child: Image.asset('assets/comprar.png'),
                ),
                label: 'Comprar',
              ),
              BottomNavigationBarItem(
                icon: Container(
                  height: 35,
                  child: Image.asset('assets/check.png'),
                ),
                label: 'Check-in',
              ),
              BottomNavigationBarItem(
                icon: Container(
                  height: 35,
                  child: Image.asset('assets/cidades.png'),
                ),
                label: 'Cidades',
              ),
              BottomNavigationBarItem(
                icon: Container(
                  height: 35,
                  child: Image.asset('assets/profile.png'),
                ),
                label: 'Perfil',
              ),
            ],
            onTap: (value) {
              controller.pageController.jumpToPage(value);
            },
          );
        },
      ),
    );
  }
}
