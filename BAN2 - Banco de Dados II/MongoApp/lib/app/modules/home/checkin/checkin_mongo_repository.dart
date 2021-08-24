import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/home/checkin/interfaces/checkin_repository_interface.dart';
import 'package:app_mobile/app/modules/home/checkin/models/reserva.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/aeroportos_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/models/aeroporto.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:dio/native_imp.dart';
import 'package:mongo_dart/mongo_dart.dart';

part 'checkin_mongo_repository.g.dart';

@Injectable()
class CheckinMongoRepository extends ICheckinRepository {
  Db db = Modular.get<AppController>().mongoConnection;

  //dispose will be called automatically
  @override
  void dispose() {}

  @override
  Future<List<Reserva>> listarReservas(int codp) async {
    List<Reserva> reservas = [];
    List<Map<String, dynamic>> jsons =
        await db.collection('reservas').find().toList();
    for (int i = 0; i < jsons.length; i++) {
      var element = jsons[i];
      Reserva r = Reserva.fromMap(element);
      int trecho = await buscarIdTrecho(int.parse(element['coda']));
      List<Aeroporto> aeroportos = await buscarOrigemDestino(trecho);
      r.origem = aeroportos[0];
      r.destino = aeroportos[1];
      print(r.origem.cidade);
      print(r.destino.cidade);
      reservas.add(r);
      print(reservas);
    }
    return reservas;
  }

  Future<List<Aeroporto>> buscarOrigemDestino(int trecho) async {
    Map<String, dynamic> json =
        await db.collection('trechos').find({'_id': trecho}).first;
    List<Aeroporto> aeroportos = [];
    aeroportos.add(await Modular.get<IAeroportosRepository>()
        .buscarAeroporto(int.parse(json['origem'])));
    aeroportos.add(await Modular.get<IAeroportosRepository>()
        .buscarAeroporto(int.parse(json['origem'])));
    return aeroportos;
  }

  Future<int> buscarIdTrecho(int coda) async {
    Map<String, dynamic> json =
        await db.collection('assentos').find({'_id': coda}).first;
    return json['codt'];
  }

  @override
  Future<void> realizarCheckin(int codr) async {
    await db.collection('reservas').update(
          where.eq('_id', codr),
          modify.set('confirmada', "true"),
        );
  }
}
