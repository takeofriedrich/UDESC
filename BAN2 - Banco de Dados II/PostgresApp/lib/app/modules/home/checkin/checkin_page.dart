import 'package:app_mobile/app/modules/home/checkin/widgets/checkin_widget.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
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
    loading = true;
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
        ),
        body: RefreshIndicator(
          child: loading
              ? Center(
                  child: CircularProgressIndicator(),
                )
              : Observer(
                  builder: (BuildContext context) {
                    return controller.reservas.isEmpty
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
