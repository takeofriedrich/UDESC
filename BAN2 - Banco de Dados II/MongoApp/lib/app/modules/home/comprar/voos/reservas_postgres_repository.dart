import 'package:app_mobile/app/modules/home/comprar/voos/interfaces/reservas_repository_interface.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:dio/native_imp.dart';

part 'reservas_postgres_repository.g.dart';

@Injectable()
class ReservasPostgresRepository extends IReservasRepository {
  final DioForNative client;

  ReservasPostgresRepository(this.client);

  Future fetchPost() async {
    final response =
        await client.get('https://jsonplaceholder.typicode.com/posts/1');
    return response.data;
  }

  //dispose will be called automatically
  @override
  void dispose() {}
}
