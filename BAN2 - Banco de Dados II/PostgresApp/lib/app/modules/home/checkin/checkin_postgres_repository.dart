import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/home/checkin/interfaces/checkin_repository_interface.dart';
import 'package:app_mobile/app/modules/home/checkin/models/reserva.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/aeroportos_repository_interface.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:postgres/postgres.dart';

part 'checkin_postgres_repository.g.dart';

@Injectable()
class CheckinPostgresRepository implements ICheckinRepository {
  PostgreSQLConnection connection = Modular.get<AppController>().connection;

  String sqlBuscarReservas = 'select * from listar_reservas(@codpP)';
  String sqlRealizarReserva = 'select * from realizarCheckIn(@codrP)';

  //dispose will be called automatically
  @override
  void dispose() {}

  @override
  Future<List<Reserva>> listarReservas(int codp) async {
    return connection.query(sqlBuscarReservas,
        substitutionValues: {'codpP': codp}).then((value) {
      List<Reserva> reservas = [];
      value.forEach((element) async {
        Reserva r = Reserva.fromMap(element.toColumnMap());
        r.origem = await Modular.get<IAeroportosRepository>()
            .buscarAeroporto(element.toColumnMap()['coda_origem_'])
            .then((value) => r.origem = value);
        r.destino = await Modular.get<IAeroportosRepository>()
            .buscarAeroporto(element.toColumnMap()['coda_destino_']);
        print(r);
        reservas.add(r);
      });
      return reservas;
    });
  }

  @override
  Future<void> realizarCheckin(int codrP) async {
    return connection
        .query(sqlRealizarReserva, substitutionValues: {'codrP': codrP});
  }
}
