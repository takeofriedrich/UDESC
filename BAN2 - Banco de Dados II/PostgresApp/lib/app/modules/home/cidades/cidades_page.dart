import 'package:app_mobile/app/modules/utils/container_borda.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:mobx/mobx.dart';
import 'cidades_controller.dart';

class CidadesPage extends StatefulWidget {
  final String title;
  const CidadesPage({Key key, this.title = "Cidades"}) : super(key: key);

  @override
  _CidadesPageState createState() => _CidadesPageState();
}

class _CidadesPageState extends ModularState<CidadesPage, CidadesController> {
  //use 'controller' variable to access controller

  bool loading = true;

  @override
  void initState() {
    super.initState();
    controller.buscarCidades().whenComplete(() {
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
                    return controller.cidades.isEmpty
                        ? Center(
                            child: ListView(
                              shrinkWrap: true,
                              children: [
                                Row(
                                  mainAxisAlignment: MainAxisAlignment.center,
                                  children: [
                                    Text('Não há cidades na lista'),
                                  ],
                                ),
                              ],
                            ),
                          )
                        : ListView.builder(
                            itemBuilder: (BuildContext context, int index) {
                              return ContainerBorda(
                                child: InkWell(
                                  child: Text(controller.cidades[index].nome),
                                  onTap: () {
                                    controller.navegarParaAeroportos(index);
                                  },
                                ),
                              );
                            },
                            itemCount: controller.cidades.length,
                          );
                  },
                ),
          onRefresh: () async {
            loading = true;
            controller.buscarCidades();
            await Future.delayed(Duration(seconds: 2));
            setState(() {
              loading = false;
            });
          }),
    );
  }
}
