import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/home/checkin/widgets/checkin_widget.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:mongo_dart/mongo_dart.dart';
import 'checkin_controller.dart';

class CheckinPage extends StatefulWidget {
  final String title;
  const CheckinPage({Key key, this.title = "Checkin"}) : super(key: key);

  @override
  _CheckinPageState createState() => _CheckinPageState();
}

class _CheckinPageState extends ModularState<CheckinPage, CheckinController> {
  //use 'controller' variable to access controller

  bool loading = true;

  @override
  void initState() {
    super.initState();
    buscar();
  }

  Future<void> buscar() async {
    setState(() {
      loading = true;
    });
    controller.buscarReservas().then((value) async {
      await Future.delayed(Duration(seconds: 2));
      setState(() {
        loading = false;
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: Text(widget.title),
          centerTitle: true,
          actions: [
            IconButton(
                icon: Icon(Icons.add),
                onPressed: () {
                  // Db db = Modular.get<AppController>().mongoConnection;
                  // for (int i = 32; i < 64; i++) {
                  //   db.collection('assentos').insert(i == 17 || i == 20
                  //       ? {'_id': i, 'codt': 2, 'reservado': true}
                  //       : {'_id': i, 'codt': 2, 'reservado': false});
                  // }
                  // print('foi!');
                })
          ],
        ),
        body: RefreshIndicator(
          child: loading
              ? Center(
                  child: CircularProgressIndicator(),
                )
              : Observer(
                  builder: (BuildContext context) {
                    return controller.reservas.isEmpty ||
                            controller.reservas == null
                        ? Center(
                            child: Text('Não há reservas na lista'),
                          )
                        : ListView.builder(
                            itemBuilder: (BuildContext context, int index) {
                              return CheckinWidget(
                                  reserva: controller.reservas[index]);
                            },
                            itemCount: controller.reservas.length,
                          );
                  },
                ),
          onRefresh: buscar,
        ));
  }
}
